#include "structs.h"

extern Gestion jeu;
extern Hero player;
extern Input input;
extern Map map;

/* Prototype des fonctions externes que nous allons utiliser ensuite */
extern SDL_Surface *loadImage(char *name);
extern void CenterScrollingOnPlayer(void);
extern void mapCollision(Hero *entity);


extern SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);

extern int collision_test (SDL_Surface *mask, int x, int y, int height);

extern int collision_perpri(Map *bg, Hero *per) ;

extern int pixel_test(SDL_Surface *surface, int x, int y);

extern void drawImage(SDL_Surface *image, int x, int y);
