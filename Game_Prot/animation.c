#include "animation.h"

/**
* @file Animation.c
* @brief  Animation For the player and the enemies
* @author Legacy Team
* @version 0.1.3
* @date Apr 18, 2019
*
* GameEngine 0.1.3
*
* Ayya Barra ay
*/
void drawanimatedplayer(Hero *player)
{


    if (player->frameTimer <= 0)
    {

        player->frameTimer = TIME_BETWEEN_2_FRAMES;

        player->frameNumber++;

        if (player->frameNumber >= player->sprite->w / PLAYER_WIDTH)
            player->frameNumber = 0;

    }
    //Sinon, on décrémente notre timer
    else
        player->frameTimer--;


    //Ensuite, on peut passer la main à notre fonction
    drawplayer(player);

}
