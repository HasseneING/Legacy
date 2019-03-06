#ifndef MENUFUNCTIONS
#define MENUFUNCTIONS




typedef struct mousexy
{
	int MOX, MOY, BOX, BOY; //MO = Movment BO = Button press
} MouseXY;

typedef struct Fps
{

	int now , ex , p_fps , dt ;//FPS
	//Periode_Fps = 33 => FPS = 30 img/s
	//Periode_Fps = 20 => FPS = 50 img/s
} FPS;

typedef struct inrect {

	int N , S, E;
} inside_rectStruct;

void init_FPSr(FPS *FPS_Reg);

void init_inrect(inside_rectStruct *inrect);

void inside_rect(int *State,MouseXY Mouse, SDL_Rect Rect, SDL_Rect Settings_rect, SDL_Rect Exit_rect,inside_rectStruct *inrect,int * running);

#endif