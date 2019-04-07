#include <stdio.h>
#include <string.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>

#define SCREEN_WIDTH 1240
#define SCREEN_HEIGHT 720

#define MAX_X 1240
#define MAX_Y 720


#define PLAYER_WIDTH 211
#define PLAYER_HEIGTH 200

#define LEFT 99
#define RIGHT 100
#define WALK 101
#define PLAYER_SPEED 4
#define TIME_BETWEEN_2_FRAMES 4

#define GRAVITY_SPEED 0.4
#define MAX_FALL_SPEED 10
#define JUMP_HEIGHT 13
