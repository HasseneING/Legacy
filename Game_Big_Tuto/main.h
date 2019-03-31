#include "structs.h"

/* Prototypes des fonctions utilisées */

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void draw(void);
extern void drawImage(SDL_Surface *image, int x, int y);
extern void loadGame(void);
extern void delay(unsigned int frameLimit);
extern void play_animation(SDL_Surface *GIF_Img[], int i, int delay, SDL_Surface *Screen, int x , int y);



/* Déclaration des structures globales utilisées par le jeu */

Input input;

Gestion jeu;

Map map;

Wolf wolf;

Menu Pausemenu;

SDL_Surface *PreMenu1[15];

SDL_Surface *PreMenu2[15];

