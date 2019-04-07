#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "header.h"




int main(void) {


	int running = 1;//Game loop
	int moveX = 1000, moveY = 200, velX = 0, velY = 0;//Char mouvment
	int now = 0, ex = 0, p_fps = 20, dt = 0;//FPS
	float delta_s = 0;
	//Periode_Fps = 33 => FPS = 30 img/s
	//Periode_Fps = 20 => FPS = 50 img/s


	SDL_Event event;


	SDL_Surface *screen;
	SDL_Surface *image;


	SDL_Rect clip[11] ;





SDL_Init(SDL_INIT_EVERYTHING);



//	image = SDL_LoadBMP("background.bmp");
	image= IMG_Load("CharacterAnimation.png");
	screen = SDL_SetVideoMode(1240, 720, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);



	//SDL_SetColorKey(ennemi, SDL_SRCCOLORKEY, SDL_MapRGB(Detective->format, 255, 255, 255));

//setrects(&clip);
int frame = 0 ;
set_clips(clip);
	while (running) {//game loop


			SDL_Flip(screen);
			SDL_BlitSurface(image,&clip[frame],screen,NULL);
			SDL_Flip(screen);
			SDL_Delay(100);
			frame ++ ;
			if (frame == 5)
				frame = 0;

	}//gameloop
	SDL_FreeSurface(image);


	SDL_QUIT;
}
