#include "Scrolling.h"
/**
* @file Scrolling.c
* @brief  this is the mouch bel3ani Scrolling
* @author Legacy Team
* @version 0.1.3
* @date Apr 18, 2019
*
* GameEngine 0.1.3
*
* Ayya Barra ay
*/

void scrolling_horizentale(SDL_Rect *camera,int droite,int gauche,int speed)
{
	if (droite==1)
	{
		camera->x=(camera->x)+speed;
	}
	else if (gauche==1)
	{
		camera->x=(camera->x)-speed;
	}
}


void display_camera(SDL_Surface *map,SDL_Rect camera,SDL_Surface *screen)
{
 SDL_Rect poscamera;
 poscamera.x=0;
 poscamera.y=0;
 SDL_BlitSurface(map,&camera,screen,&poscamera);
 SDL_Flip(screen);
}
