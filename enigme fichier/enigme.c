#include "enigme.h"

//variable globlale
int appele_srand=0;
char tab_chaine[TAILLE_tab][TAILLE_MAX]= {""};
//initialiser srand
void initialiser_aleat(unsigned int n)
{
    srand(n);
    appele_srand = 1;
}
//generation d'un nombre aléatoire entre min et max
int nombre_aletoire(int min, int max)
{
    if(appele_srand != 1)
        initialiser_aleat((unsigned)time(NULL));
    return rand()%(max-min+1) + min;
}
//nombre de questions dans le fichier
int nombre_de_ligne(FILE* f)
{
    char *ch=(char*)malloc(TAILLE_MAX * sizeof(char));
    int i=0;
    char c;
    do
    {
        printf("%d\n",i);
        c = fgetc(f);
        if(c!='*')
        {
            fgets(ch,TAILLE_MAX,f);
            printf("%s\n",ch);
            i++;
        }
    }
    while(c!='*');
    return(i-1);
}
//afficher les sous surface à l'écrant
void apply_surface( SDL_Rect offset, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_BlitSurface( source, NULL, destination, &offset );
}
//initialisation sdl et ttf et ajouter l'image de fond
SDL_Surface *initialiser_enigme(int h,int w,int posx,int posy)
{
    SDL_Surface *surface=NULL,*fond=NULL;
    SDL_Rect position;
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return NULL;
    }
    surface = SDL_SetVideoMode(h,w, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_NOFRAME);
    if( surface == NULL )
    {
        return NULL;
    }
    if( TTF_Init() == -1 )
    {
        return NULL;
    }
    SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format, 255, 255, 255));
    fond =IMG_Load("bg.png");
    position.x = 0;
    position.y = 0;
    apply_surface( position,fond,surface);
    SDL_Flip(surface);
    return surface;
}
//couper les différent partie d'une chaine de caractére
void upload_info(char ch1[],int com_max)
{
    char ch2[TAILLE_MAX]="";
    char ch3[TAILLE_MAX]="";
    char *chaine;
    int j=0;
    int com=com_max-5;
    while(com<com_max)
    {
        j=0;
        memcpy(ch2, ch1, strlen(ch1)+1);
        chaine = strtok(ch2, ";");
        for(int i=0; i<=strlen(chaine); i++)
        {
            tab_chaine[com][i]=ch2[i];
        }
        com++;
        for(int i=strlen(chaine)+1; i<=strlen(ch1); i++)
        {
            ch3[j]=ch1[i];
            j++;
        }
        strcmp(ch1, "");
        memcpy(ch1, ch3, strlen(ch3)+1);
    }
}
//télécharger les ligne de fichier dand la matrice tab_chaine
void get_lines(FILE* f,int nbr)
{
    char chaine[TAILLE_MAX]="";
    fseek(f,0, SEEK_SET);
    int ind=5;
    for(int i=0; i<=nbr; i++)
    {
        fgets(chaine,TAILLE_MAX,f);
        upload_info(chaine,ind);
        ind+=5;
    }
}
//écrire du texte dans la surface
void draw_texte(SDL_Surface *screen,SDL_Surface *texte,SDL_Color couleur,TTF_Font *police,SDL_Rect position,int i)
{
    texte = TTF_RenderText_Solid(police,tab_chaine[i],couleur);
    if(texte==NULL)
    {
        EXIT_FAILURE;
    }
    apply_surface( position,texte,screen);
    SDL_Flip(screen);
    SDL_FreeSurface(texte);

}
//replissage de tableau des position pour les texte
void create_rect(SDL_Rect pos[])
{
    pos[0].x=0;
    pos[0].y=50;
    pos[1].x=0;
    pos[1].y=200;
    pos[2].x=200;
    pos[2].y=200;
    pos[3].x=400;
    pos[3].y=200;
}
//faire le traitement et donner la notification est ce que la réponce choisie est juste ou non
int traitement_reponce(int mx,int my,char a)
{
    int verif=0;
    if(((mx>0)&&(mx<100))&&((my>200)&&(my<300))&&(a=='1'))
    {
        verif=1;
    }
    else if(((mx>200)&&(mx<300))&&((my>200)&&(my<300))&&(a=='2'))
    {
        verif=1;
    }
    else if(((mx>400)&&(mx<500))&&((my>200)&&(my<300))&&(a=='3'))
    {
        verif=1;
    }
    return (verif);
}
//vider les surface et la police et quitter sdl et ttf
void clean_up(SDL_Surface *screen,SDL_Surface *texte,TTF_Font *police)
{
    SDL_FreeSurface( screen );
    SDL_FreeSurface( texte );
    TTF_CloseFont( police );
    TTF_Quit();
    SDL_Quit();
}
void enigme()
{
    SDL_Surface *screen=NULL,*texte=NULL;
    int continuer=1;
    SDL_Event event;
    SDL_Color couleur = {0,0,0};
    SDL_Color couleur_v = {27,250,57};
    SDL_Color couleur_f = {255,0,0};
    screen=initialiser_enigme(500,300,0,0);
    TTF_Font *police = NULL;
    SDL_Rect position[TAILLE_tab];
    create_rect(position);
    police = TTF_OpenFont("Ceria Lebaran.otf",25);
    TTF_SetFontStyle(police,TTF_STYLE_BOLD);
    FILE* f=fopen("test.txt", "r");
    int nbr_ligne=nombre_de_ligne(f);
    get_lines(f,nbr_ligne);
    int i=nombre_aletoire(0,nbr_ligne)*5;
    while (continuer)
    {
        while( SDL_PollEvent( &event ) )
        {
            //SDL_WaitEvent(&event);
            switch(event.type)
            {
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    int mx,my;
                    SDL_GetMouseState(&mx,&my);
                    int verification=traitement_reponce(mx,my,tab_chaine[i+4][0]);
                    if(verification==1)
                    {
                        screen=initialiser_enigme(500,300,0,0);
                        int com_pos=0;
                        for(int k=i; k<=i+3; k++)
                        {
                            draw_texte(screen,texte,couleur_v,police,position[com_pos],k);
                            com_pos++;
                        }
                        SDL_Delay(1000);
                        continuer = 0;
                    }
                    else if(verification==0)
                    {
                        screen=initialiser_enigme(500,300,0,0);
                        int com_pos=0;
                        for(int k=i; k<=i+3; k++)
                        {
                            draw_texte(screen,texte,couleur_f,police,position[com_pos],k);
                            com_pos++;
                        }
                        SDL_Delay(1000);
                        int x=0;
                        int verif=1;
                        while(verif)
                        {
                            x=nombre_aletoire(0,nbr_ligne)*5;
                            if(x!=i)
                            {
                                verif=0;
                            }
                        }
                        i=x;
                        screen=initialiser_enigme(500,300,0,0);
                    }

                }
                break;
            }
            int com_pos=0;
            for(int k=i; k<=i+3; k++)
            {
                draw_texte(screen,texte,couleur,police,position[com_pos],k);
                com_pos++;
            }
        }
    }
    clean_up(screen,texte,police);
    fclose(f);
}
