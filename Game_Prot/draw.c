#include "draw.h"
/**
* @file Draw.c
* @brief  Mostly Drawing things on the screen in a very "clever" way
* @author Legacy Team
* @version 0.1.3
* @date Apr 18, 2019
*
* GameEngine 0.1.3
*
* Ayya Barra ay
*/
void drawImage(SDL_Surface *image, int x, int y)
{
	SDL_Rect dest;

	/* Règle le rectangle à blitter selon la taille de l'image source */

	dest.x = x;
	dest.y = y;
	dest.w = image->w;
	dest.h = image->h;

	/* Blitte l'image entière sur l'écran aux coordonnées x et y */

	SDL_BlitSurface(image, NULL, jeu.screen, &dest);
}


void play_animation(SDL_Surface *GIF_Img[], int i, int delay, SDL_Surface *Screen, int x , int y) {

	for (int k = 0 ; k <= i; k++) {
		SDL_Flip(Screen);
		drawImage(GIF_Img[k], x, y);
		SDL_Flip(Screen);
		SDL_Delay(delay);
	}
}


void drawanimatedplayer(Hero *player)
{

	if (player->frameTimer <= 0)
	{

		player->frameTimer = TIME_BETWEEN_2_FRAMES;

		player->frameNumber++;

		if (player->frameNumber >= player->sprite->w / 157)
			player->frameNumber = 0;

	}
	else
		player->frameTimer--;
	drawplayer(player);
}

// need to be revisited
void animate_enemy(Enemy *enemy,int Enemy_Width)
{

	if (enemy->frameTimer <= 0)
	{
		enemy->frameTimer = TIME_BETWEEN_2_FRAMES;

		enemy->frameNumber++;

		if (enemy->frameNumber >= enemy->Spritesheet->w / Enemy_Width)
			enemy->frameNumber = 0;
	}
	else
		enemy->frameTimer--;
	drawEnemy(enemy,155,130);
}


SDL_Surface *loadImage(char *name)
{
	/* Charge une image temporaire avec SDL Image */

	SDL_Surface *temp = IMG_Load(name);
	SDL_Surface *image;

	/* Si elle n'est pas chargée on quitte avec une erreur */
	if (temp == NULL)
	{
		printf("Failed to load image %s\n", name);

		return NULL;
	}

	/* Ajoute la transparence à l'image temporaire en accord avec les defines TRANS_R, G, B */

	//SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(temp->format, TRANS_R, TRANS_G,    TRANS_B));


	/* Convertit l'image au format de l'écran (screen) pour un blit plus rapide */

	image = SDL_DisplayFormat(temp);

	/* Libère l'image temporaire */
	SDL_FreeSurface(temp);

	if (image == NULL)
	{
		printf("Failed to convert image %s to native format\n", name);
		return NULL;
	}
	/* Retourne l'image au format de l'écran pour accélérer son blit */
	return image;
}

void delay(unsigned int frameLimit)
{

	unsigned int ticks = SDL_GetTicks();
	if (frameLimit < ticks)
	{
		return;
	}
	if (frameLimit > ticks + 16)
	{
		SDL_Delay(16);
	}

	else
	{
		SDL_Delay(frameLimit - ticks);
	}
}
void init_Levels(void)
{
	if (map.level == 0 ) // Tavern / Training Grounds 1
		{///home/hasseneing/Desktop/GAME_GIT/Legacy/Game_Prot/MENUart/Levels/LnLevel0-1Small.png
			map.background = loadImage("/home/hasseneing/Desktop/GAME_GIT/Legacy/Game_Prot/MENUart/Levels/Lvl01.png");
			map.Map_Objects_Sprite_Sheet = IMG_Load("/home/hasseneing/Desktop/GAME_GIT/Legacy/Game_Prot/MENUart/Levels/Lvl01Masque.bmp");
		}
	if (map.level == 1 )// Tavern / Training Grounds 2
	{
		map.background = loadImage("/home/hasseneing/Desktop/GAME_GIT/Legacy/Game_Prot/MENUart/Levels/Lvl02.png");
		map.Map_Objects_Sprite_Sheet = IMG_Load("/home/hasseneing/Desktop/GAME_GIT/Legacy/Game_Prot/MENUart/Levels/Lvl02Masque.bmp");
	}

	if (map.level == 2 )// Tavern / Training Grounds 3
	{
		map.background = IMG_Load("/home/hasseneing/Desktop/GAME_GIT/Legacy/Game_Prot/MENUart/Levels/Lvl03.png");
		map.Map_Objects_Sprite_Sheet = IMG_Load("/home/hasseneing/Desktop/GAME_GIT/Legacy/Game_Prot/MENUart/Levels/Lvl03Masque.bmp");
	}
}
void draw(void)
{

	SDL_BlitSurface(map.background,&map.Camera,jeu.screen,NULL);
	//Spawn_Knight(Knight);
	SDL_Delay(1);
}
