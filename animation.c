#include "animation.h"


void drawanimatedplayer()
{

    
    if (player.frameTimer <= 0)
    {

        player.frameTimer = TIME_BETWEEN_2_FRAMES;

        player.frameNumber++;

        if(player.frameNumber >= player.sprite->w / PLAYER_WIDTH)
            player.frameNumber = 0;

    }
    //Sinon, on décrémente notre timer
    else
        player.frameTimer--;


    //Ensuite, on peut passer la main à notre fonction
    drawplayer();

}  