#include "structs.h"

/* Prototypes des fonctions utilisées */

extern void init(char *);//Init a Screen with the name in param
extern void cleanup(void);// Free the surfaces Used
extern void getInput(Input *input);// SDL_Events Takes input and changes var inside a var INPUT.LEFT = 1
extern void draw(void);// Draws a Background each Frame with a 1ms delay
extern void drawanimatedplayer(Hero *player);// Draws an animated player
extern void drawplayer(Hero *player);// Draws an idle player
extern void drawImage(SDL_Surface *image, int x, int y);//Draws an image with coords as param
extern void drawGameObject(SDL_Surface *image, int destx, int desty, int srcx, int srcy, int objwidth, int objheight);
extern void loadGame(void);//Loads all the pictures to memory
extern void delay(unsigned int frameLimit);// delay
extern void play_animation(SDL_Surface *GIF_Img[], int i, int delay, SDL_Surface *Screen, int x , int y);//Plays a full screen anim
extern void update(void);
extern void updatePlayer(Hero *player);//Player Movement management
extern void  initializePlayer(Hero *player);//Init Player (after a death or new level)
extern void init_Levels(void);





/* Déclaration des structures globales utilisées par le jeu */

Input input;

Gestion jeu;

Map map;

Wolf wolf;

Menu Pausemenu;

SettingsM SettingsMenu;

Enemy Knight;

Hero player;

SDL_Surface *PreMenu1[15];

SDL_Surface *PreMenu2[15];
