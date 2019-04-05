#include "collision.h"

SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
  SDL_Color color;

  Uint32 col = 0;

//Determine position

  char* pPosition = (char* ) pSurface->pixels;

  pPosition += (pSurface->pitch * y);

  pPosition += (pSurface->format->BytesPerPixel * x);

  memcpy(&col , &pPosition ,pSurface->format->BytesPerPixel );//
//convertir color

  SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
  return (color);
}

int collision_perpri(Map *bg, Hero *per) // collision personage principale avec obstacle
{
  int verif = 0;
  int i;
  SDL_Color couleur[7];
  //pixel color perso pri
  couleur[0] = GetPixel (bg->Map_Objects_Sprite_Sheet, per->x + (int)per->w * 1 / 3 , per->y ); //head 1/3 x
  couleur[1] = GetPixel (bg->Map_Objects_Sprite_Sheet, per->x + (int)per->w * 2 / 3 , per->y ); //head 2/3 x
  couleur[2] = GetPixel (bg->Map_Objects_Sprite_Sheet, per->x + per->w          , per->y + (int)per->h / 2 ); //hand right
  couleur[3] = GetPixel (bg->Map_Objects_Sprite_Sheet, per->x                   , per->y + (int)per->h / 2 ); // hand left
  couleur[4] = GetPixel (bg->Map_Objects_Sprite_Sheet, per->x                   , per->y + per->h ); // foot left
  couleur[5] = GetPixel (bg->Map_Objects_Sprite_Sheet, per->x + per->w          , per->y + per->h ); // foot right
  couleur[6] = GetPixel (bg->Map_Objects_Sprite_Sheet, per->x + (int)per->w / 2   , per->y + per->h ); // foot mid

  for (i = 0; i < 7; i++)
  {
    if ((couleur[i].r == 0) && ((couleur[i].g == 0) && (couleur[i].b == 0))) // a changer
    {
      verif = 1;
      break;
    }
  }
  if (verif == 1 )
  {
    if ((i == 0) && (i == 3) && (i == 4))
    {
      return LEFT;
    }
    else if ((i == 5) && (i == 2))
      return RIGHT;
    else if (((i == 6)&&(i==5)&&(i==4)) || (i == 1))
      return 1;
  }
   else return 0;

}
/**/
/*
int collision_test (SDL_Surface *mask, int x, int y, int height)
{
  int i;
  Uint8 r, g, b;
  for (i = y; i <= y + height - 10; i++)
  {
    SDL_GetRGB(GetPixel(mask, x, i), mask->format, &r, &g, &b);
    if (r == 0 && g == 0 && b == 0) break;
  }

  if (i <= y + height - 10) return 0;
  else return 1;
}
*/


/*
int pixel_test(SDL_Surface *surface, int x, int y)
{
  Uint8 r, g, b;
  SDL_GetRGB(GetPixel(surface, x, y), surface->format, &r, &g, &b);
  if (r == 0 && g == 0 && b == 0)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
*/
