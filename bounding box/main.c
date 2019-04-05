#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <string.h>
#include "perso.h"

int main()
{
	perso tab[8];
    int x,y;
        char photo[]="1.png";
        strcpy(tab[1].ch,photo);
	SDL_Surface *screen;

	screen = SDL_SetVideoMode(1024,768, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL) {
        printf("Unable to set video mode: %s \n", SDL_GetError());
        return 1;
    }
    
	initperso(&tab[1],0,0);
	while(1)
	{
	afficherperso(tab[1],screen);
    }
	return 0;
}
