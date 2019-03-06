#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include "MenuFunctions.h"

void inside_rect(int *State,MouseXY Mouse, SDL_Rect Rect, SDL_Rect Settings_rect, SDL_Rect Exit_rect, inside_rectStruct *inrect,int *running) {

	//New Game
	if ((Mouse.MOX > Rect.x) && (Mouse.MOX < Rect.x + Rect.w) && (Mouse.MOY > Rect.y) && (Mouse.MOY < Rect.y + Rect.h)) {
		inrect->N = 1;
		*State=3;
	}
	else
	{
		inrect->N = 0;
	}
	//Settings
	if ((Mouse.MOX > Settings_rect.x) && (Mouse.MOX < Settings_rect.x + Settings_rect.w) && (Mouse.MOY > Settings_rect.y) && (Mouse.MOY < Settings_rect.y + Settings_rect.h)) {
		inrect->S = 1;
		*State=2;
	}
	else
	{
		inrect->S = 0;
	}
	if ((Mouse.MOX > Exit_rect.x) && (Mouse.MOX < Exit_rect.x + Exit_rect.w) && (Mouse.MOY > Exit_rect.y) && (Mouse.MOY < Exit_rect.y + Exit_rect.h)) {
		inrect->E = 1;
		*State=1;
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





