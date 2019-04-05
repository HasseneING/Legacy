#include "structs.h"

SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);
/*renvoie l'adresse d'un pixel, x et y sont les coordonnées de ce pixel */

int collision_test (SDL_Surface *mask, int x, int y, int height);
/* detecte la collision avec un mask, height est la hauteur du joueur, x et y sont les coordonnées du joueur,cette fonction retoune 0 s'il y a pas collision avec background et 1 s'il y'en a*/

int collision_perpri(Map *bg, Hero *per); // collision personage principale avec obstacle


int pixel_test(SDL_Surface *surface, int x, int y);
/* fonction qui permet de detecter la couleur d un pixel, les coordonnées du pixel sont x et y, la fonction retourne 0 si la couleur est Black et 1 sinon */


extern Map map;
