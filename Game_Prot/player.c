#include "player.h"

void initializePlayer(void)
{

	player.sprite = IMG_Load("MENUart/Enemies/Wolf_Running.png");

	player.direction = RIGHT;

	player.etat = WALK;

	player.frameNumber = 0;
	player.frameTimer = 8;

	player.x = 300;
	player.y = 300;

	player.dirY=0;
	player.dirX=0;

	player.w = PLAYER_WIDTH;
	player.h = PLAYER_HEIGTH;

	player.timerMort = 0;
	player.onGround = 0;

	player.coll = 0;

}

void drawplayer()
{
	/* Rectangle de destination à blitter */
	SDL_Rect dest;

	// On soustrait des coordonnées de notre héros, ceux du début de la map, pour qu'il colle
	//au scrolling :
	dest.x = player.x ;
	dest.y = player.y ;
	dest.w = PLAYER_WIDTH;
	dest.h = PLAYER_HEIGTH;

	/* Rectangle source à blitter */
	SDL_Rect src;

	//Pour connaître le X de la bonne frame à blitter, il suffit de multiplier
	//la largeur du sprite par le numéro de la frame à afficher -> 0 = 0; 1 = 40; 2 = 80...
	src.x = player.frameNumber * PLAYER_WIDTH;
	src.y = 0;
	src.w = PLAYER_WIDTH;
	src.h = PLAYER_HEIGTH;

	/* Blitte notre héros sur l'écran aux coordonnées x et y */

	SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);
	//drawImage(player.sprite, player.x, player.y);

}


/*
void CenterScrollingOnPlayer(void)
{
	//On définit les coordonnées du début de l'affichage de la map par rapport à celles
	//du joueur.
	//Pour centrer le joueur, la map doit donc s'afficher à un demi-écran avant la position
	//du joueur.
	//Puis on "clamp" (limite) l'affichage de l'écran pour ne pas sortir de la map.
	map.startX = player.x - (SCREEN_WIDTH / 2);

	if (map.startX < 0)
	{
		map.startX = 0;
	}

	else if (map.startX + SCREEN_WIDTH >= map.maxX)
	{
		map.startX = map.maxX - SCREEN_WIDTH;
	}

	map.startY = player.y - (SCREEN_HEIGHT / 2);

	if (map.startY < 0)
	{
		map.startY = 0;
	}

	else if (map.startY + SCREEN_HEIGHT >= map.maxY)
	{
		map.startY = map.maxY - SCREEN_HEIGHT;
	}
}
*/


void Show_Player_Info(Hero player)
{

	system("clear");
printf("Player.x = %d\n",player.x );
printf("Player.y = %d\n",player.y );
printf("Player.dirX = %.2f\n",player.dirX );
printf("Player.dirY = %.2f\n",player.dirY );
printf("Player.coll = %d\n",player.coll );
printf("Player.direction(L=99,R=100) = %d\n",player.direction );
printf("Player.onGround = %d\n",player.onGround );
printf("Player.w = %d\n",player.w );
printf("Player.h = %d\n",player.h );
printf("Player.frameNumber = %d\n",player.frameNumber );
printf("Player.etat = %d\n",player.etat );

}
void updatePlayer(void)
{

	if (player.timerMort == 0)
	{
		player.dirX = 0;
	if(player.onGround==0)
			player.dirY +=GRAVITY_SPEED;

		if (player.dirY >= MAX_FALL_SPEED)
		{
			player.dirY = MAX_FALL_SPEED;
		}

		if (input.left == 1)
		{
			player.dirX -= PLAYER_SPEED;
			if (player.direction == RIGHT)
			{
				player.direction = LEFT;
				player.sprite = IMG_Load("MENUart/Enemies/Wolf_RunningL.png");
			}
		}

		else if (input.right == 1)
		{
			player.dirX += PLAYER_SPEED;
			if (player.direction == LEFT)
			{
				player.direction =  RIGHT;
				player.sprite = IMG_Load("MENUart/Enemies/Wolf_Running.png");
			}
		}
		if (input.jump == 1 && player.onGround)
 		{
 			player.dirY = -JUMP_HEIGHT;
 			player.onGround = 0;
 		}
		
		player.x += player.dirX;
		player.y += player.dirY;

		mapCollision(&player);
		system("clear");
		Show_Player_Info(player);
	}

	if (player.timerMort > 0)
	{
		player.timerMort--;
		}
		if (player.y>1000)
			player.timerMort= -1;
		if (player.timerMort < 0)
			{
				SDL_Delay(1000);
				initializePlayer();
	}

}
