#include "structs.h"

/* Prototypes des fonctions utilisées */

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void draw(void);
extern void drawImage(SDL_Surface *image, int x, int y);
extern void drawGameObject(SDL_Surface *image, int destx, int desty, int srcx, int srcy, int objwidth, int objheight);
extern void loadGame(void);
extern void delay(unsigned int frameLimit);
extern void play_animation(SDL_Surface *GIF_Img[], int i, int delay, SDL_Surface *Screen, int x , int y);
extern void update(void);
extern void updatePlayer(void);
extern void initializePlayer(void);




/* Déclaration des structures globales utilisées par le jeu */

Input input;

Gestion jeu;

Map map;

Wolf wolf;

Menu Pausemenu;

SettingsM SettingsMenu;

Hero player;

SDL_Surface *PreMenu1[15];

SDL_Surface *PreMenu2[15];
