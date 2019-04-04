#ifndef HEADER_H_
#define HEADER_H_
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <math.h>
typedef enum state state;
enum state {waitin,followin, attackin} ;


typedef struct {
int life;
SDL_Surface * image;
SDL_Rect pos_e;

state state;


}ennemi;



distance(Hero player,ennemi e);
void mvt_aleatoire_es(ennemi*es,SDL_Surface *screen,SDL_Rect clip []);
void move_fb_ennemi(ennemi*es,SDL_Rect clip[]);
void movment_right_ennemi(ennemi*es,SDL_Rect clip[]);
void move_left_ennemi(ennemi *es,SDL_Rect clip[]);
void set_clips(SDL_Rect* clip);
void play_animation(SDL_Surface *GIF_Img[], int i, int delay, SDL_Surface Screen, int x , int y);
void afficher_es(ennemi*es,SDL_Surface *screen,SDL_Rect clip );
void animation_ennemi(SDL_Rect clip ,SDL_Surface*image,SDL_Surface **screen,int *frame,int max_frame);






#endif /* HEADER_H_ */
