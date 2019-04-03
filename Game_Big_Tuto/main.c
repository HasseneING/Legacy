#include "main.h"
#include "draw.h"

int main( int argc, char *argv[ ] )
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int playLOOP = 0;
    int AnimLOOP = 1;
    int mainLOOP = 1;
    int menuLOOP = 0;
    int settingLOOP = 0;
    int Etat = 0 ;

    init("Prophecy");
    /* On initialise le joueur */
    //  initializePlayer();
    loadGame();
    atexit(cleanup);

    play_animation(PreMenu1, 14, 34, jeu.screen, 0, 0);

    while (mainLOOP)
    {
        while (AnimLOOP)
        {

            getInput();

            if (input.enter == 1)
            {
                play_animation(PreMenu2, 14, 34, jeu.screen, 0, 0);
                AnimLOOP = 0 ;
                menuLOOP = 1;
            }
        }


        while (menuLOOP)
        {
            SDL_Flip(jeu.screen);
            SDL_BlitSurface(MainMenu.Bg, NULL, jeu.screen, NULL);

            getInput();

            //drawImage(MainMenu.Bg, 0, 0);
            if (Etat == 1)//PLAY Highlighted
                drawImage(MainMenu.Button1HL, 0, 0);
            else
                drawImage(MainMenu.Button1, 0, 0);
            if (Etat == 2)//Settings Highlighted
                drawImage(MainMenu.Button2HL, 0, 0);
            else
                drawImage(MainMenu.Button2, 0, 0);
            /*if (Etat == 3)//Credits Highlighted
                drawImage(MainMenu.Button3HL, 0, 0);
            else
                drawImage(MainMenu.Button3, 0, 0);*/
            if (Etat == 4)//exit Highlighted
                drawImage(MainMenu.Button4HL, 0, 0);
            else
                drawImage(MainMenu.Button4, 0, 0);

            if (Etat >= 5)
                Etat = 0;
            if (Etat <= -1)
                Etat = 5 ;
            if (input.down == 1)
                Etat++;
            SDL_Delay(30);
            if (input.up == 1)
                Etat--;
            SDL_Delay(30);

            if ((Etat == 1) && (input.enter == 1)) // play
            {
                menuLOOP = 0;
                playLOOP = 1;
            }


            if ((Etat == 2) && (input.enter == 1)) //Settings
            {
                menuLOOP = 0;
                settingLOOP = 1;
            }


            /*if ((Etat == 3)&&(input.enter==1))//Credits
            {

            }
            */

            if ((Etat == 4) && (input.enter == 1)) //exit
            {
                menuLOOP = 0;
            }




            delay(frameLimit);
            frameLimit = SDL_GetTicks() + 16;
            SDL_Flip(jeu.screen);
        }

        while (playLOOP == 1)
        {

            /* On vérifie l'état des entrées (clavier puis plus tard joystick */
            getInput();

            // update();

            /* On affiche tout */
            draw();

            //  update();

            /* Gestion des 60 fps ( 60 images pas seconde : soit 1s ->1000ms/60 = 16.6 -> 16
            On doit donc attendre 16 ms entre chaque image (frame) */
            delay(frameLimit);
            frameLimit = SDL_GetTicks() + 16;

        }
        while (settingLOOP == 1)
        {   
            getInput();
            printf("im in \n");
        }

    }
    /* Exit */
    exit(0);

}

