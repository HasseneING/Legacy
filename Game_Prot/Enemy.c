#include "Enemy.h"

/**
* @file Enemy.c
* @brief  Initiallizing enemies / Spawning them
* @author Legacy Team
* @version 0.1.3
* @date Apr 18, 2019
*
* GameEngine 0.1.3
*
* Ayya Barra ay
*/
void initEnemies()
{
	Knight.Pos.x = 600; Knight.Pos.y = 200; Knight.frameNumber = 0;
}
void drawEnemy(Enemy *enemy, int Enemy_Height, int Enemy_Width)
{
	SDL_Rect dest;

	// On soustrait des coordonnées de notre héros, ceux du début de la map, pour qu'il colle
	//au scrolling :
	dest.x = enemy->x ;
	dest.y = enemy->y ;
	dest.w = Enemy_Width;
	dest.h = Enemy_Height;

	/* Rectangle source à blitter */
	SDL_Rect src;

	//Pour connaître le X de la bonne frame à blitter, il suffit de multiplier
	//la largeur du sprite par le numéro de la frame à afficher -> 0 = 0; 1 = 40; 2 = 80...
	src.x = enemy->frameNumber * Enemy_Width;
	src.y = 0;
	src.w = Enemy_Width;
	src.h = Enemy_Height;

	/* Blitte notre héros sur l'écran aux coordonnées x et y */

	SDL_BlitSurface(enemy->Spritesheet, &src, jeu.screen, &dest);

}


void initialise_en(ennemi *es, char file_name[], int x, int y)
{
	(*es).pos_e.x = x;
	(*es).pos_e.y = y;
	es->image = IMG_Load(file_name);
}


void mvtaleatoirees(ennemi*es, char file_name[], char file_name0[], int *a, int min , int max) {
	srand(time(NULL));

	*a = ((rand() % 2));

	if ((*a == 1) && (es->pos_e.x != max)) {
		es->image = IMG_Load(file_name);
		es->pos_e.x += 10;
	}
	else if ((*a == 2) && (es->pos_e.x != min)) {
		es->image = IMG_Load(file_name0);
		es->pos_e.x -= 10;
	}

	else
		es->pos_e.x = es->pos_e.x;

}

void setClips(SDL_Rect clips[]) {

	clips[0].x = 0;
	clips[0].y = 0;
	clips[0].w = 155;
	clips[0].h = 123;

	clips[1].x = 152;
	clips[1].y = 0;
	clips[1].w = 155;
	clips[1].h = 123;

	clips[2].x = 297;
	clips[2].y = 0;
	clips[2].w = 138;
	clips[2].h = 123;

	clips[3].x = 443;
	clips[3].y = 0;
	clips[3].w = 146;
	clips[3].h = 123;
}



void Spawn_Knight(Enemy Knight)
{
	SDL_Rect dest, clip[4];
	setClips(clip);

	mvtaleatoirees(&Knight , "/home/hasseneing/Desktop/GAME_GIT/Legacy/Game_Prot/MENUart/Enemies/gargoyle.png" , "/home/hasseneing/Desktop/GAME_GIT/Legacy/Game_Prot/MENUart/Enemies/gargoyleL.png" , 2, 0, 900);

	// dest.x = Knight.x ;
	// dest.y = Knight.y ;
	// dest.w = Knight.w;
	// dest.h = Knight.h;

	Knight.frameNumber++;
	if (Knight.frameNumber >= 4)
		Knight.frameNumber = 0;

	SDL_BlitSurface(Knight.Spritesheet, &clip[Knight.frameNumber], jeu.screen, &Knight.Pos);

}
