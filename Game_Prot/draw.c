

#include "draw.h"

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


void drawanimatedplayer()
{

    if (player.frameTimer <= 0)
    {
<<<<<<< HEAD

=======
      
>>>>>>> ae5f2aa1a0f72022c0687cd99cf7f9da872c69c6
        player.frameTimer = TIME_BETWEEN_2_FRAMES;

        player.frameNumber++;

        if(player.frameNumber >= player.sprite->w / PLAYER_WIDTH)
            player.frameNumber = 0;

    }
    else
        player.frameTimer--;
    drawplayer();
<<<<<<< HEAD
}


=======
}  
>>>>>>> ae5f2aa1a0f72022c0687cd99cf7f9da872c69c6
void draw(void)
{

	/* Affiche le fond (background) aux coordonnées (0,0) */
	drawImage(map.background,-(player.x-400)/4, 0);
	//CenterScrollingOnPlayer();

	/* Affiche le joueur */
	if ((input.left == 1)||( input.right == 1))
		drawanimatedplayer();
<<<<<<< HEAD
	else
=======
	else 
>>>>>>> ae5f2aa1a0f72022c0687cd99cf7f9da872c69c6
		drawplayer(); // Idle
	/* Affiche l'écran */
	SDL_Flip(jeu.screen);

	/* Delai */
	SDL_Delay(1);
}


<<<<<<< HEAD

=======
>>>>>>> ae5f2aa1a0f72022c0687cd99cf7f9da872c69c6
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

	/* Gestion des 60 fps (images/stories/seconde) */

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
<<<<<<< HEAD
=======

>>>>>>> ae5f2aa1a0f72022c0687cd99cf7f9da872c69c6
