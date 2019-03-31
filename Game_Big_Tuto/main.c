#include "main.h"
#include "draw.h"

int main( int argc, char *argv[ ] )
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int playLOOP = 0;
    int AnimLOOP = 1;
    int mainLOOP = 1;
    int menuLOOP = 0;

    init("Prophecy");
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
            getInput();
            drawImage(Pausemenu.Bg, 0, 0);
            SDL_Flip(jeu.screen);
            if (state == 1)//PLAY Highlighted
                drawImage(Pausemenu.Button1HL, 0, 0);
            else
                drawImage(Pausemenu.Button1, 0, 0);
            if (state == 2)//Settings Highlighted
                drawImage(Pausemenu.Button2HL, 0, 0);
            else
                drawImage(Pausemenu.Button2, 0, 0);
            if (state == 3)//Credits Highlighted
                drawImage(Pausemenu.Button3HL, 0, 0);
            else
                drawImage(Pausemenu.Button3, 0, 0);
            if (state == 4)//exit Highlighted
                drawImage(Pausemenu.Button4HL, 0, 0);
            else
                drawImage(Pausemenu.Button4, 0, 0);
            SDL_Flip(jeu.screen);
        }

        while (playLOOP == 1)
        {

            /* On vérifie l'état des entrées (clavier puis plus tard joystick */
            getInput();

            /* On affiche tout */
            draw();

            /* Gestion des 60 fps ( 60 images pas seconde : soit 1s ->1000ms/60 = 16.6 -> 16
            On doit donc attendre 16 ms entre chaque image (frame) */
            delay(frameLimit);
            frameLimit = SDL_GetTicks() + 16;

        }

    }
    /* Exit */
    exit(0);

}

