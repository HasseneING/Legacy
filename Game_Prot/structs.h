#ifndef STRUCTS
#define STRUCTS

#include "defs.h"


typedef struct Input
{

	int left, right, up, down, jump, attack, enter, erase, pause;

} Input;


typedef struct Gestion
{
	SDL_Surface *screen;
} Gestion;


typedef struct Map
{

	SDL_Surface *background,*Map_Objects_Sprite_Sheet;

	int startX, startY;
	int maxX, maxY;



} Map;


typedef struct Hero
{

	SDL_Surface *sprite,*anim[4];

	/* Coordonnées du héros */
	int x, y;
	/* Largeur, hauteur du sprite */
	int h, w;

	/* Variables utiles pour l'animation */
	int frameNumber, frameTimer;
	int etat, direction;

	/* Variables utiles pour la gestion des collisions */
	int onGround, timerMort;
	float dirX, dirY;

	int coll;


} Hero;




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
