#ifndef STRUCTS
#define STRUCTS

#include "defs.h"

/* Structures qui seront utilisées pour gérer le jeu */

/* Structure pour gérer l'input (clavier puis joystick) */

typedef struct Input
{

	int left, right, up, down, jump, attack, enter, erase, pause;

} Input;


/* Structure pour gérer le niveau (à compléter plus tard) */

typedef struct Gestion
{

	SDL_Surface *screen;

} Gestion;

/* Structure pour gérer la map à afficher (à compléter plus tard) */

typedef struct Map
{

	SDL_Surface *background;

} Map;

typedef struct wolf
{
	SDL_Surface *Wolf_anim;
} Wolf;

typedef struct Menus
{
	SDL_Surface *Bg;
	SDL_Surface *Button1, *Button2, *Button3, *Button4, *Button5, *Button1HL, *Button2HL, *Button3HL, *Button4HL;
} Menu ;


/*Play any Full Screen Animation*/


void play_animation(SDL_Surface *GIF_Img[], int i, int delay , SDL_Surface *Screen, int x , int y);

/* Press Any button Rectangles Setting*/

void set_rects(SDL_Rect *clip3);


#endif
