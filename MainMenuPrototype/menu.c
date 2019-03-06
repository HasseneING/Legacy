#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include "MenuFunctions.h"




int main(void) {
	int running = 1;
	int settingsLOOP = 0;
	int playLOOP = 0;
	int gameloop1 = 1;
	int State = 4;
	int ETAT ;
	const int SCREEN_HEIGHT = 720;
	const int SCREEN_WIDTH = 1280;



	MouseXY Mouse;

	inside_rectStruct inrect;
	init_inrect(&inrect);

	FPS FPS_Reg;
	init_FPSr(&FPS_Reg);


	SDL_Event event;

	SDL_Surface *Screen = NULL;
	SDL_Surface *BackGround = NULL;
	SDL_Surface *Title = NULL;
	SDL_Surface *NewGame = NULL;
	SDL_Surface *Settings = NULL;
	SDL_Surface *Exit = NULL;
	SDL_Surface *NewGameHL = NULL;
	SDL_Surface *SettingsHL = NULL;
	SDL_Surface *ExitHL = NULL;
	SDL_Surface *BacktoM = NULL;
	SDL_Surface *BacktoMHL = NULL;
	SDL_Surface *Controles = NULL;
	SDL_Surface *ControlesHL = NULL;
	SDL_Surface *Volume = NULL;
	SDL_Surface *VolumeHL = NULL;
	SDL_Surface *VolHigh = NULL;
	SDL_Surface *VolHighHL = NULL;
	SDL_Surface *VolLow = NULL;
	SDL_Surface *VolLowHL = NULL;
	SDL_Surface *VolMed = NULL;
	SDL_Surface *VolMedHL = NULL;
	SDL_Surface *PaperBG = NULL;



	SDL_Rect NewGame_rect = {480, 110, 145, 300};
	SDL_Rect Settings_rect = {480, 280, 145, 300};
	SDL_Rect Exit_rect = {480, 485, 145, 300};


	Mix_Chunk *woosh = NULL;
	Mix_Music *Intro = NULL;
	if ( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
		return 0;
	}
	woosh = Mix_LoadWAV("MENUart/Sounds/Key_press.wav");
	Intro = Mix_LoadMUS("MENUart/Sounds/Intro.wav");
	Mix_PlayMusic( Intro, -1 );

	SDL_Init(SDL_INIT_VIDEO);
	const SDL_VideoInfo *pinfo = SDL_GetVideoInfo();
	int bpp = pinfo->vfmt->BitsPerPixel;


	//MENU BUTTONS
	BackGround = IMG_Load("MENUart/backg.jpg");
	NewGame = IMG_Load("MENUart/play.png");
	Settings = IMG_Load("MENUart/setting.png");
	Exit = IMG_Load("MENUart/quit.png");
	NewGameHL = IMG_Load("MENUart/play high.png");
	SettingsHL = IMG_Load("MENUart/settings high.png");
	ExitHL = IMG_Load("MENUart/quit high.png");
	BacktoM = IMG_Load("MENUart/Back-to-menu.png");



	Screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, bpp, SDL_HWSURFACE | SDL_DOUBLEBUF );
	SDL_WM_SetCaption("Prophecy", NULL);

	system("cvlc /home/hasseneing/Desktop/MainMenu/MENUdone.mp4");




	while (gameloop1) {

		while (running) {//game loop

			//FPS Regulation
			FPS_Reg.now = SDL_GetTicks();
			FPS_Reg.dt = FPS_Reg.now - FPS_Reg.ex ;
			if (FPS_Reg.dt > FPS_Reg.p_fps)
			{

				//Surface Blitting aka Menu Init
				SDL_BlitSurface(BackGround, NULL, Screen, NULL);
				SDL_BlitSurface(NewGame, NULL, Screen, NULL);
				SDL_BlitSurface(Settings, NULL, Screen, NULL);
				SDL_BlitSurface(Exit, NULL, Screen, NULL);

				// Highlights
				if ((State == 3) || (inrect.N == 1))
					SDL_BlitSurface(NewGameHL, NULL, Screen, NULL);


				if ((State == 2 ) || (inrect.S == 1))
					SDL_BlitSurface(SettingsHL, NULL, Screen, NULL);


				if ((State == 1) || (inrect.E == 1))
					SDL_BlitSurface(ExitHL, NULL, Screen, NULL);


				SDL_PollEvent(&event);

				switch (event.type) {
				case SDL_QUIT:
					running = 0;
					break;
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_DOWN)

					{
						if (State <= 0) {
							State = 4;
						}
						State--;
						SDL_Delay(100);
					}
					if (event.key.keysym.sym == SDLK_UP)

					{
						if (State >= 4) {
							State = 0;
						}
						State++;
						SDL_Delay(100);
					}
					if (event.key.keysym.sym == SDLK_RETURN)

					{	if (State == 1)//Quit
						{
							Mix_PlayChannel( -1, woosh, 0 );
							running = 0;
						}
						if (State == 2)//Settings
						{
							Mix_PlayChannel( -1, woosh, 0 );
							settingsLOOP = 1;
							running = 0;
						}
						if (State == 3)//Play
						{
							Mix_PlayChannel( -1, woosh, 0 );
							playLOOP = 1;
							running = 0;
						}
					}


				case SDL_MOUSEMOTION:

					Mouse.MOX = event.motion.x;
					Mouse.MOY = event.motion.y;
					inside_rect(&State, Mouse, NewGame_rect, Settings_rect, Exit_rect, &inrect, &running);
					break;

				case SDL_MOUSEBUTTONDOWN:

					Mouse.BOY = event.button.x;
					Mouse.BOX = event.button.y;
					if ((Mouse.MOX > NewGame_rect.x) && (Mouse.MOX < NewGame_rect.x + NewGame_rect.w) && (Mouse.MOY > NewGame_rect.y) && (Mouse.MOY < NewGame_rect.y + NewGame_rect.h)) {
						playLOOP = 1;
						running = 0;
					}
					if ((Mouse.MOX > Settings_rect.x) && (Mouse.MOX < Settings_rect.x + Settings_rect.w) && (Mouse.MOY > Settings_rect.y) && (Mouse.MOY < Settings_rect.y + Settings_rect.h)) {
						running = 0;
						settingsLOOP = 1;
					}
					if ((Mouse.MOX > Exit_rect.x) && (Mouse.MOX < Exit_rect.x + Exit_rect.w) && (Mouse.MOY > Exit_rect.y) && (Mouse.MOY < Exit_rect.y + Exit_rect.h)) {

						running = 0;
						SDL_QUIT;
					}

					break;

				}//Switch


				//	SDL_FillRect(BackGround, &NewGame_rect, SDL_MapRGB(BackGround->format, 255, 255, 255)); TEST RECT
				SDL_Flip(Screen);
				FPS_Reg.ex = FPS_Reg.now;
			}
			else {
				SDL_Delay(FPS_Reg.p_fps - FPS_Reg.dt);
			}
		}//gameloop



//SETTINGS BUTTONS

		BacktoM = IMG_Load("MENUart/Settings_pngs/Back.png");
		BacktoMHL = IMG_Load("MENUart/Settings_pngs/BackHL.png");

		Controles = IMG_Load("MENUart/Settings_pngs/Controles.png");
		ControlesHL = IMG_Load("MENUart/Settings_pngs/ControlesHL.png");

		Volume = IMG_Load("MENUart/Settings_pngs/Volume.png");
		VolumeHL = IMG_Load("MENUart/Settings_pngs/VolumeHL.png");

		VolHigh = IMG_Load("MENUart/Settings_pngs/High.png");
		VolHighHL = IMG_Load("MENUart/Settings_pngs/HighHL.png");


		VolMed = IMG_Load("MENUart/Settings_pngs/Med.png");
		VolMedHL = IMG_Load("MENUart/Settings_pngs/MedHL.png");

		VolLow = IMG_Load("MENUart/Settings_pngs/Low.png");
		VolLowHL = IMG_Load("MENUart/Settings_pngs/LowHL.png");

		PaperBG = IMG_Load("MENUart/Settings_pngs/temp.png");


		SDL_Flip(Screen);
		ETAT = 7;

		while (settingsLOOP != 0) {
			SDL_BlitSurface(BackGround, NULL, Screen, NULL);
			SDL_BlitSurface(PaperBG, NULL, Screen , NULL);




			if (ETAT == 6)
				SDL_BlitSurface(BacktoMHL, NULL, Screen, NULL);
			else
				SDL_BlitSurface(BacktoM, NULL, Screen , NULL);

			if (ETAT == 5)
				SDL_BlitSurface(ControlesHL, NULL, Screen , NULL);
			else
				SDL_BlitSurface(Controles, NULL, Screen , NULL);

			if (ETAT == 4)
				SDL_BlitSurface(VolumeHL, NULL, Screen , NULL);
			else
				SDL_BlitSurface(Volume, NULL, Screen , NULL);

			if (ETAT == 3)
				SDL_BlitSurface(VolLowHL, NULL, Screen , NULL);
			else
				SDL_BlitSurface(VolLow, NULL, Screen , NULL);

			if (ETAT == 2)
				SDL_BlitSurface(VolMedHL, NULL, Screen , NULL);
			else
				SDL_BlitSurface(VolMed, NULL, Screen , NULL);

			if (ETAT == 1)
				SDL_BlitSurface(VolHighHL, NULL, Screen , NULL);
			else
				SDL_BlitSurface(VolHigh, NULL, Screen , NULL);








			SDL_PollEvent(&event);

			switch (event.type) {
			case SDL_QUIT:
				settingsLOOP = 0;
				break;

			case SDL_KEYDOWN:
				if ((event.key.keysym.sym == SDLK_DOWN) || (event.key.keysym.sym == SDLK_RIGHT))

				{
					if (ETAT <= 0) {
						ETAT = 7;
					}
					ETAT--;
					SDL_Delay(100);
				}
				if ((event.key.keysym.sym == SDLK_UP) || (event.key.keysym.sym == SDLK_LEFT))

				{
					if (ETAT >= 6) {
						ETAT = 0;
					}
					ETAT++;
					SDL_Delay(100);
				}
			}

			SDL_Flip(Screen);

		}

		Mix_FreeChunk( woosh );
		Mix_FreeMusic( Intro );
		Mix_CloseAudio();



		SDL_FreeSurface(BackGround);
		SDL_FreeSurface(NewGame);
		SDL_FreeSurface(Settings);
		SDL_FreeSurface(Exit);
		SDL_FreeSurface(NewGameHL);
		SDL_FreeSurface(SettingsHL);
		SDL_FreeSurface(ExitHL);
	}//GAME LOOP 1

	SDL_QUIT;
}





