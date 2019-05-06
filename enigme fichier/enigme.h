#define TAILLE_MAX 100
#define TAILLE_tab 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//prototype des fonction
void initialiser_aleat(unsigned int n);
int nombre_aletoire(int min, int max);
int nombre_de_ligne(FILE* f);
void apply_surface( SDL_Rect offset, SDL_Surface* source, SDL_Surface* destination);
SDL_Surface *initialiser_enigme(int h,int w,int posx,int posy);
void upload_info(char ch1[],int com_max);
void get_lines(FILE* f,int nbr);
void draw_texte(SDL_Surface *screen,SDL_Surface *texte,SDL_Color couleur,TTF_Font *police,SDL_Rect position,int i);
void create_rect(SDL_Rect pos[]);
int traitement_reponce(int mx,int my,char a);
void clean_up(SDL_Surface *screen,SDL_Surface *texte,TTF_Font *police);
void enigme();

