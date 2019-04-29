#include "main.h"
#include "draw.h"
/**
* @file main.c
* @brief  GameEngine
* @author Legacy Team
* @version 0.1.3
* @date Apr 18, 2019
*
* GameEngine 0.1.3
*
* Ayya Barra ay
*/
int main( int argc, char *argv[ ] )
{
  unsigned int frameLimit = SDL_GetTicks() + 16;
  int playLOOP = 0;
  int AnimLOOP = 1;
  int mainLOOP = 1;
  int menuLOOP = 0;
  int settingsLOOP = 0;
  int controlesLOOP=0;
  int Etat = 0, ETAT = 0;


  init("Prophecy");
  /* On initialise le joueur */
  initializePlayer(&player);
  loadGame();
  atexit(cleanup);

  play_animation(PreMenu1, 14, 34, jeu.screen, 0, 0);

  while (mainLOOP)
  {
    while (AnimLOOP)
    {

      getInput(&input);

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
      SDL_BlitSurface(Pausemenu.Bg, NULL, jeu.screen, NULL);

      getInput(&input);

      if (Etat == 1)//PLAY Highlighted
        drawImage(Pausemenu.Button1HL, 0, 0);
      else
        drawImage(Pausemenu.Button1, 0, 0);
      if (Etat == 2)//Settings Highlighted
        drawImage(Pausemenu.Button2HL, 0, 0);
      else
        drawImage(Pausemenu.Button2, 0, 0);
      /*if (Etat == 3)//Credits Highlighted
          drawImage(Pausemenu.Button3HL, 0, 0);
      else
          drawImage(Pausemenu.Button3, 0, 0);*/
      if (Etat == 4)//exit Highlighted
        drawImage(Pausemenu.Button4HL, 0, 0);
      else
        drawImage(Pausemenu.Button4, 0, 0);

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
        settingsLOOP = 1;

      }


      /*if ((Etat == 3)&&(input.enter==1))//Credits
      {

      }
      */


      if ((Etat == 4) && (input.enter == 1)) //exit
      {
        menuLOOP = 0;
        mainLOOP = 0;
      }


      delay(frameLimit);
      frameLimit = SDL_GetTicks() + 16;
      SDL_Flip(jeu.screen);
    }


    ETAT = 7;
    while (settingsLOOP)
    {
      getInput(&input);
      SDL_Flip(jeu.screen);
      SDL_BlitSurface(Pausemenu.Bg, NULL, jeu.screen, NULL);
      SDL_BlitSurface(SettingsMenu.PaperBG, NULL, jeu.screen , NULL);

      if (ETAT == 6)
        SDL_BlitSurface(SettingsMenu.BacktoMHL, NULL, jeu.screen, NULL);
      else
        SDL_BlitSurface(SettingsMenu.BacktoM, NULL, jeu.screen , NULL);

      if (ETAT == 5)
        SDL_BlitSurface(SettingsMenu.ControlesHL, NULL, jeu.screen , NULL);
      else
        SDL_BlitSurface(SettingsMenu.Controles, NULL, jeu.screen , NULL);

      if (ETAT == 4)
        SDL_BlitSurface(SettingsMenu.VolumeHL, NULL, jeu.screen , NULL);
      else
        SDL_BlitSurface(SettingsMenu.Volume, NULL, jeu.screen , NULL);

      if (ETAT == 3)
        SDL_BlitSurface(SettingsMenu.VolLowHL, NULL, jeu.screen , NULL);
      else
        SDL_BlitSurface(SettingsMenu.VolLow, NULL, jeu.screen , NULL);

      if (ETAT == 2)
        SDL_BlitSurface(SettingsMenu.VolMedHL, NULL, jeu.screen , NULL);
      else
        SDL_BlitSurface(SettingsMenu.VolMed, NULL, jeu.screen , NULL);

      if (ETAT == 1)
        SDL_BlitSurface(SettingsMenu.VolHighHL, NULL, jeu.screen , NULL);
      else
        SDL_BlitSurface(SettingsMenu.VolHigh, NULL, jeu.screen , NULL);

      if (ETAT >= 7)
        ETAT = 0;
      if (ETAT <= -1)
        ETAT = 7 ;
      if (input.down == 1)
      {
        SDL_Delay(10);

        ETAT--;
      }
      if (input.up == 1)
      {
        SDL_Delay(10);

        ETAT++;
      }
      if ((input.enter == 1) && (ETAT == 6))//Back
      {
        settingsLOOP = 0;
        menuLOOP = 1;
      }
      if ((input.enter == 1) && (ETAT == 5))//Controles
      {
        settingsLOOP=0;
        controlesLOOP=1;
      }
      if ((input.enter == 1) && (ETAT == 3))//Vol Low
      {

      }
      if ((input.enter == 1) && (ETAT == 2))//Vol Mid
      {

      }
      if ((input.enter == 1) && (ETAT == 1))//Vol High
      {

      }


      delay(frameLimit);
      frameLimit = SDL_GetTicks() + 16;
    }


    map.level = 0;

    while (playLOOP == 1)
    {

      /* On vérifie l'état des entrées (clavier puis plus tard joystick */
      initializePlayer(&player);
      init_Levels();
      while (map.level == 0)
      {
          getInput(&input);
          //printf("map.bg.w=%d\n",map.background->w );

          draw();//Draw Bg
          /* Affiche le joueur */

          if ((input.left == 1) || ( input.right == 1))
            drawanimatedplayer(&player);
          else
            drawplayer(&player); // Idle

          updatePlayer(&player);//player 1

          SDL_Flip(jeu.screen);

          if (player.x >=SCREEN_WIDTH)// map.Camera.x+map.Camera.w
            {
              play_animation(PreMenu2, 14, 60, jeu.screen, 0, 0);
              map.level++;
            }
      }
      initializePlayer(&player);
      init_Levels();
      while(map.level==1)
      {
        getInput(&input);

        draw(/*Need to pass a map*/);

        Spawn_Knight(Knight);

        if ((input.left == 1) || ( input.right == 1))
          drawanimatedplayer(&player);
        else
          drawplayer(&player); // Idle

        updatePlayer(&player);//player 1

        SDL_Flip(jeu.screen);
        if ((player.x>=966)&&(player.x<=1094) && (player.onGround))
          {
            initializePlayer(&player);
          }
        if (player.x >= map.background->w-100)
          {
            play_animation(PreMenu2, 14, 60, jeu.screen, 0, 0);
            map.level++;
          }
          if (player.x <= 0)
            {
              play_animation(PreMenu2, 14, 60, jeu.screen, 0, 0);
              map.level--;
            }
      }
      initializePlayer(&player);
      init_Levels();
      while(map.level==2)
      {

        printf("working in prog\n" );
      }
      delay(frameLimit);
      frameLimit = SDL_GetTicks() + 16;
    }

  }
  /* Exit */
  exit(0);

}
