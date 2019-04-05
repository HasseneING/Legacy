#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include "header.h"
//init_enemi
void initialise_en(ennemi * es,char file_name){
es->pos_e.x=;
es->pos_e.y=;
es->image=
IMG_Load_("file_name");

}




initialise_ennemi(SDL_Surface*image,char file_name[]){

image= IMG_Load(file_name);
SDL_Init(SDL_INIT_EVERYTHING);
    
SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 255, 255, 255));
if (image==NULL) {
				printf("Unable to load bitmap: %s\n", SDL_GetError());
				BE=1;
			}
else
BE=0;
return BE;
}


void animation_ennemi(SDL_Rect clip ,SDL_Surface*image,SDL_Surface **screen,int *frame,int max_frame){


            SDL_Flip(screen);
            SDL_BlitSurface(image,&clip[*frame],screen,NULL);
            SDL_Flip(screen);
            SDL_Delay(100);
                    (*frame )++ ;
            if (*frame == max_frame)
                *frame = 0;
}

//affichage methode 2:

void afficher_ennemi(SDL_Surface image, int x, int y)
{
SDL_Rect dest;

    

dest.x = x;
dest.y = y;
    dest.w = image->w;
    dest.h = image->h;


    SDL_BlitSurface(image, NULL, jeu.screen, &dest);
}

void afficher_es(ennemi*es,SDL_Surface *screen,SDL_Rect clip ){
SDL_BlitSurface(es->image,NULL,screen,&es->pos_e);
SDL_Flip(screen);


}
void play_animation(SDL_Surface *GIF_Img[], int i, int delay, SDL_Surface Screen, int x , int y) {

    for (int k = 0 ; k <= i; k++) {
        SDL_Flip(Screen);
        drawImage(GIF_Img[k], x, y);
        SDL_Flip(Screen);
        SDL_Delay(delay);
    }
} 



void set_clips(SDL_Rect* clip)
{
    //Clip the sprites
    clip[ 0 ].x =4 ;
    clip[ 0 ].y =256 ;
    clip[ 0 ].w =172 ;
    clip[ 0 ].h =356 ;
    
    clip[ 1 ].x = 169;
    clip[ 1 ].y =256  ;
    clip[ 1 ].w =172 ;
    clip[ 1 ].h =356 ;
    
    clip[ 2 ].x = 334;
    clip[ 2 ].y =256 ;
    clip[ 2 ].w =172 ;
    clip[ 2 ].h =356 ;
    
    clip[ 3 ].x = 499;
    clip[ 3 ].y =256 ;
    clip[ 3 ].w =172 ;
    clip[ 3 ].h =356 ;

     clip[ 4 ].x =664 ;
    clip[ 4 ].y =256 ;
    clip[ 4 ].w =172 ;
    clip[ 4 ].h =356 ;

    clip[ 5 ].x =829 ;
    clip[ 5 ].y =256 ;
    clip[ 5 ].w =172 ;
    clip[ 5 ].h =356 ;

    
}

//movment_left
void move_left_ennemi(ennemi *es,SDL_Rect clip[]){
int a;
a=((rand()%6)+1);
switch(a){
case 1:
es->image=clip[];
break;
case 2:
es->image=clip[];
break;
case 3:
es->image=clip[];
break;
case 4:
es->image=clip[];
break;



}


}

void movment_right_ennemi(ennemi*es,SDL_Rect clip[]){
int a;
a=((rand()%6)+1);
switch(a){
case 1:
es->image=clip[];
break;
case 2:
es->image=clip[];
break;
case 3:
es->image=clip[];
break;
case 4:
es->image=clip[];
break;


}

void move_fb_ennemi(ennemi*es,SDL_Rect clip[]){
es-image= clip[];

}


// movment  aleatoire
void mvt_aleatoire_es(ennemi*es,SDL_Surface *screen,SDL_Rect clip []){
srand(time(NULL));
int a;
a=((rand(%5)+1));
if(a==1){
movment_right_ennemi(es,clip);
es->pos_e.x+=;
es->pos_e.y+=;


}
else
if(a==2){
move_left_Ennemi(es,clip);
es->pos_e.x-=;
es->pos_e.y-=;

}
else
if(a==3){
move_fb_ennemi(es,clip);//L9odem
es->pos_e.x+=;
es->pos_e.y -=;


}
else
{
move_fb_ennemi(es,clip);//lteli
es->pos_e.x-=10;
es->pos_e.y+=10;

}
}



distance(Hero player,ennemi e){
int a,b,c,d,k,l;
a=player.x;
b=player.y;
c=e.pos_e.x;
d=e.pos_e.y;
k=(a-c)*(a-c);
l=(b-d)*(b-d);
return sqrt(k+l);
}


void updating_ennemi(ennemi*e,Hero h,SDL_Surface*screen,SDL_Rect clip[]){
switch(e->state){
case waitin:
mvt_aleatoire_es(e,screen,clip);
break;
case followin:
if((h.x < e->pos_e.x)&&(h.y<e->pos_e.y))
{

e->pos_e.x-=10;
e->pose.y-=10;
move_left_Ennemi(e,clip);

}
else 
if((h.x>e->pos_e.x)&&(h.y>e->pos_e.y) ){
e->pos_e.x+=10;
e->pos_e.y+=10;
movment_right_ennemi(e,clip);
}
else
if((h.x>e->pos_e.x)&&(h.y<e->pos_e.y)){
e->pos_e.x+=10;
e->pos_e.y-=10;
move_fb_ennemi(e,clip);
}
else
if((h.x<e->pos_e.x)&& (h.y>e->pos_e.y)){
e->pos_e.x-=10;
e->pos_e.y+=10;
move_fb_ennemi(e,clip);


}
break;
case attackin:
if((h.x < e->pos_e.x)&&(h.y < e->pos_e.y))
move_left_Ennemi(e,clip);
else
if((h.x > e->pos_e.x)&&(h.y > e->pos_e.y))
    movment_right_ennemi(e,clip);
else
    if((h.x > e->pos_e.x)&&(h.y < e->pos_e.y))
    move_fb_ennemi(e,clip);
else
if((h.x < e->pos_e.x)&&(h.y > e->pos_e.y))
move_fb_ennemi(e,clip);
break;



}
}

void IA(ennemi e,Hero h,int d1,int d2,SDL_Surface *screen){
if((distance(h,e)<d1)&&(e.state==waitin)){
e.state=followin;

}
else
if((distance(h,e)>d1)&&(e.state==followin)){

ennemi.state=waitin;

}
else
if((distance(h,e)<d2)&&(e.state==followin)){
e.state=attackin;
h.life--;


}
else
if((distance(h,e)<d2)&&(h.life==0)&&(ennemi.state==attackin)){

ennemi.state=waitin;


}
else
if((distance(h,e) < d1)&&(distance(h,e)>d2)&&(e.state==attackin))
{
e.state=followin;

}
updating_ennemi(&e,p,screen);
}










