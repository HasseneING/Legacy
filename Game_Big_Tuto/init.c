#include "init.h"

/* Fonction qui initialise le jeu */

void init(char *title)
{
  if (SDL_Init(SDL_INIT_EVERYTHING ) < 0)
  {
    printf("Could not initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }
  jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (jeu.screen == NULL)
  {
    printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
    exit(1);
  }

  SDL_WM_SetCaption(title, NULL);
  SDL_ShowCursor(SDL_DISABLE);

}

void loadGame(void)
{
// Anything Loaded By this function Has to be declared in Main.h, init.h, Draw.h
  /* Charge l'image du fond */
  map.background = loadImage("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/Levels/Lvl01.png");
  wolf.Wolf_anim = loadImage("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/Enemies/Wolf_Running.png");
  Pausemenu.Bg = loadImage("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/backg.jpg");
  Pausemenu.Button1=loadImage("/MENUart/play.png");
  Pausemenu.Button2=loadImage("/MENUart/backg.png");
  Pausemenu.Button3=loadImage("/MENUart/backg.png");
  Pausemenu.Button4=loadImage("/MENUart/backg.png");
  Pausemenu.Button1HL=loadImage("/MENUart/backg.png");
  Pausemenu.Button2HL=loadImage("/MENUart/backg.png");
  Pausemenu.Button3HL=loadImage("/MENUart/backg.png");
  Pausemenu.Button4HL=loadImage("/MENUart/backg.png");
  PreMenu1[0] = loadImage("MENUart/Premenu/1MENU065.png");
  PreMenu1[1] = loadImage("MENUart/Premenu/2MENU065.png");
  PreMenu1[2] = loadImage("MENUart/Premenu/3MENU065.png");
  PreMenu1[3] = loadImage("MENUart/Premenu/4MENU065.png");
  PreMenu1[4] = loadImage("MENUart/Premenu/5MENU065.png");
  PreMenu1[5] = loadImage("MENUart/Premenu/6MENU065.png");
  PreMenu1[6] = loadImage("MENUart/Premenu/7MENU065.png");
  PreMenu1[7] = loadImage("MENUart/Premenu/8MENU065.png");
  PreMenu1[8] = loadImage("MENUart/Premenu/9MENU065.png");
  PreMenu1[9] = loadImage("MENUart/Premenu/10MENU065.png");
  PreMenu1[10] = loadImage("MENUart/Premenu/11MENU065.png");
  PreMenu1[11] = loadImage("MENUart/Premenu/12MENU065.png");
  PreMenu1[12] = loadImage("MENUart/Premenu/13MENU065.png");
  PreMenu1[13] = loadImage("MENUart/Premenu/14MENU065.png");
  PreMenu1[14] = loadImage("MENUart/Premenu/15MENU065.png");
  PreMenu2[0] = loadImage("MENUart/Premenu/16MENU065.png");
  PreMenu2[1] = loadImage("MENUart/Premenu/17MENU065.png");
  PreMenu2[2] = loadImage("MENUart/Premenu/18MENU065.png");
  PreMenu2[3] = loadImage("MENUart/Premenu/19MENU065.png");
  PreMenu2[4] = loadImage("MENUart/Premenu/20MENU065.png");
  PreMenu2[5] = loadImage("MENUart/Premenu/21MENU065.png");
  PreMenu2[6] = loadImage("MENUart/Premenu/22MENU065.png");
  PreMenu2[7] = loadImage("MENUart/Premenu/23MENU065.png");
  PreMenu2[8] = loadImage("MENUart/Premenu/24MENU065.png");
  PreMenu2[9] = loadImage("MENUart/Premenu/25MENU065.png");
  PreMenu2[10] = loadImage("MENUart/Premenu/26MENU065.png");
  PreMenu2[11] = loadImage("MENUart/Premenu/27MENU065.png");
  PreMenu2[12] = loadImage("MENUart/Premenu/28MENU065.png");
  PreMenu2[13] = loadImage("MENUart/Premenu/29MENU065.png");
  PreMenu2[14] = loadImage("MENUart/Premenu/30MENU065.png");
}
/* Fonction qui quitte le jeu proprement */
void cleanup()
{
  if (map.background != NULL)
  {
    SDL_FreeSurface(map.background);
    SDL_FreeSurface(wolf.Wolf_anim);
  }
  /* Quitte la SDL */
  SDL_Quit();
}

