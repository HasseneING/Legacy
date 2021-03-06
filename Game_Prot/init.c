#include "init.h"

/* Fonction qui initialise le jeu */

void init(char *title)
{
  initEnemies();

  if (SDL_Init(SDL_INIT_EVERYTHING ) < 0)
  {
    printf("Could not initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }
  map.Camera.w=SCREEN_WIDTH;
  	map.Camera.h=SCREEN_HEIGHT;
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
  
  Pausemenu.Bg = IMG_Load("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/backg.jpg");
  Pausemenu.Button1 = IMG_Load("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/play.png");     // play
  Pausemenu.Button2 = IMG_Load("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/setting.png"); // settings
// Pausemenu.Button3=IMG_Load("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/credits .png");   // creds
  Pausemenu.Button4 = IMG_Load("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/quit.png");     // quit
  Pausemenu.Button1HL = IMG_Load("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/play high.png");
  Pausemenu.Button2HL = IMG_Load("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/settings high.png");
// Pausemenu.Button3HL=IMG_Load("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/credits high.png");
  Pausemenu.Button4HL = IMG_Load("/home/hasseneing/Desktop/Game_Big_Tuto/MENUart/quit high.png");

  SettingsMenu.BacktoM = IMG_Load("MENUart/Settings_pngs/Back.png");
  SettingsMenu.BacktoMHL = IMG_Load("MENUart/Settings_pngs/BackHL.png");

  SettingsMenu.Controles = IMG_Load("MENUart/Settings_pngs/Controles.png");
  SettingsMenu.ControlesHL = IMG_Load("MENUart/Settings_pngs/ControlesHL.png");

  SettingsMenu.Volume = IMG_Load("MENUart/Settings_pngs/Volume.png");
  SettingsMenu.VolumeHL = IMG_Load("MENUart/Settings_pngs/VolumeHL.png");

  SettingsMenu.VolHigh = IMG_Load("MENUart/Settings_pngs/High.png");
  SettingsMenu.VolHighHL = IMG_Load("MENUart/Settings_pngs/HighHL.png");


  SettingsMenu.VolMed = IMG_Load("MENUart/Settings_pngs/Med.png");
  SettingsMenu.VolMedHL = IMG_Load("MENUart/Settings_pngs/MedHL.png");

  SettingsMenu.VolLow = IMG_Load("MENUart/Settings_pngs/Low.png");
  SettingsMenu.VolLowHL = IMG_Load("MENUart/Settings_pngs/LowHL.png");

  SettingsMenu.PaperBG = IMG_Load("MENUart/Settings_pngs/temp.png");


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
  }
  /* Quitte la SDL */
  SDL_Quit();
}
