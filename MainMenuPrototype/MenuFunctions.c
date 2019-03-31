#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include "MenuFunctions.h"

void inside_rect(int *State, MouseXY Mouse, SDL_Rect Rect, SDL_Rect Settings_rect, SDL_Rect Exit_rect, inside_rectStruct *inrect, int *running) {

	//New Game
	if ((Mouse.MOX > Rect.x) && (Mouse.MOX < Rect.x + Rect.w) && (Mouse.MOY > Rect.y) && (Mouse.MOY < Rect.y + Rect.h)) {
		inrect->N = 1;
		*State = 3;
	}
	else
	{
		inrect->N = 0;
	}
	//Settings
	if ((Mouse.MOX > Settings_rect.x) && (Mouse.MOX < Settings_rect.x + Settings_rect.w) && (Mouse.MOY > Settings_rect.y) && (Mouse.MOY < Settings_rect.y + Settings_rect.h)) {
		inrect->S = 1;
		*State = 2;
	}
	else
	{
		inrect->S = 0;
	}
	if ((Mouse.MOX > Exit_rect.x) && (Mouse.MOX < Exit_rect.x + Exit_rect.w) && (Mouse.MOY > Exit_rect.y) && (Mouse.MOY < Exit_rect.y + Exit_rect.h)) {
		inrect->E = 1;
		*State = 1;
	}
	else
	{
		inrect->E = 0;
	}



}

void init_FPSr(FPS *FPS_Reg) {

	FPS_Reg->now = 0; FPS_Reg->ex = 0; FPS_Reg->p_fps = 5; FPS_Reg->dt = 0;
}

void init_inrect(inside_rectStruct *inrect) {

	inrect->N = 0;// inrect->E = 0; inrect->S = 0;
}





void play_animation(SDL_Surface *GIF_Img[], int i, int delay, SDL_Surface *Screen) {

	for (int k = 0 ; k <= i; k++) {
		SDL_Flip(Screen);
		SDL_BlitSurface(GIF_Img[k], NULL, Screen, NULL);
		SDL_Flip(Screen);
		SDL_Delay(delay);
	}
}

void set_rects(SDL_Rect *clip3)
{
	clip3[0].x = 110 ;
	clip3[0].y = 30 ;
	clip3[0].w = 693;
	clip3[0].h = 215;

	clip3[1].x = 879 ;
	clip3[1].y = 30 ;
	clip3[1].w = 693;
	clip3[1].h = 215;

	clip3[2].x = 1664 ;
	clip3[2].y = 30 ;
	clip3[2].w = 693;
	clip3[2].h = 215;

	clip3[3].x = 2449 ;
	clip3[3].y = 30 ;
	clip3[3].w = 693;
	clip3[3].h = 2115;

	clip3[4].x = 3210 ;
	clip3[4].y = 30 ;
	clip3[4].w = 693;
	clip3[4].h = 215;

	//2nd row
	clip3[5].x = 110 ;
	clip3[5].y = 254 ;
	clip3[5].w = 693;
	clip3[5].h = 215;

	clip3[6].x = 879 ;
	clip3[6].y = 254 ;
	clip3[6].w = 693;
	clip3[6].h = 215;

	clip3[7].x = 1664 ;
	clip3[7].y = 254 ;
	clip3[7].w = 693;
	clip3[7].h = 215;

	clip3[8].x = 2449 ;
	clip3[8].y = 254 ;
	clip3[8].w = 693;
	clip3[8].h = 215;

	clip3[9].x = 3210 ;
	clip3[9].y = 254 ;
	clip3[9].w = 693;
	clip3[9].h = 215;

	//3rd row

	clip3[10].x = 110 ;
	clip3[10].y = 479 ;
	clip3[10].w = 693;
	clip3[10].h = 215;

	clip3[11].x = 879 ;
	clip3[11].y = 479 ;
	clip3[11].w = 693;
	clip3[11].h = 215;

	clip3[12].x = 1664 ;
	clip3[12].y = 479 ;
	clip3[12].w = 693;
	clip3[12].h = 215;

	clip3[13].x = 2449 ;
	clip3[13].y = 479 ;
	clip3[13].w = 693;
	clip3[13].h = 215;

	clip3[14].x = 3210 ;
	clip3[14].y = 479 ;
	clip3[14].w = 693;
	clip3[14].h = 215;

	//4th row
	clip3[15].x = 110 ;
	clip3[15].y = 704 ;
	clip3[15].w = 693;
	clip3[15].h = 215;

	clip3[16].x = 879 ;
	clip3[16].y = 704 ;
	clip3[16].w = 693;
	clip3[16].h = 215;

	clip3[17].x = 1664 ;
	clip3[17].y = 704 ;
	clip3[17].w = 693;
	clip3[17].h = 215;

	clip3[18].x = 2449 ;
	clip3[18].y = 704 ;
	clip3[18].w = 693;
	clip3[18].h = 215;

	clip3[19].x = 3210 ;
	clip3[19].y = 704 ;
	clip3[19].w = 693;
	clip3[19].h = 215;

}