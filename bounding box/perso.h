#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <string.h>

typedef struct perso
{
	SDL_Rect position;
	int aord;
	SDL_Surface* image;
	char ch[10];
	int col;

	SDL_Surface* up[2];
	SDL_Surface* down[2];
	SDL_Surface* left[2];
	SDL_Surface* right[2];


}perso;

void initperso(perso* p,int x,int y);
void afficherperso(perso p,SDL_Surface *screen);
/*void deplacement(perso* p,SDL_Event event,SDL_Surface *screen);
int playerscol(perso p1,perso p2);*/
#endif