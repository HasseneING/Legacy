#include <stdio.h>
#include <stdlib.h>
#include "perso.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <string.h>

void initperso(perso* p,int x,int y)
{
	p.image = IMG_Load(p->ch);
	if (p.image == NULL) {
                printf("Unable to load the image: %s\n", SDL_GetError());
            }

     p->position.x = x;
     p->position.y = y;
     p->position.w = image->w;
     p->position.h = image->h;
     
     p->aord=1;
     p->col=0;

}

void afficherperso(perso p,SDL_Surface *screen)
{
   SDL_BlitSurface(p.omage , NULL, screen, &p.position);
}

int playerscol(perso p1,perso p2)
{
  int test=1;

    if(p1.position.x + p1.position.w < p2.position.x)
      test=0;
    
    if(p1.position.x > p2.position.x + p2.position.w)
      test=0;
    
    if(p1.position.y + p1.position.h < p2.position.y)
      test=0;
    
    if(p1.position.y > p2.position.y + p2.position.h)
      test=0;

  return test;
}

void deplacement(perso* p,SDL_Event event,SDL_Surface *screen)
{
     switch(event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
             for(int i = 0; i<3; i++){
                SDL_BlitSurface(p->up[i], NULL,screen,&p->position);
                SDL_Delay(60);}
            p->position.y -=5;           
            break;
            
            case SDLK_DOWN:
             for(int i = 0; i<3; i++){
                SDL_BlitSurface(p->down[i], NULL,screen,&p->position);
                SDL_Delay(60);}
            p->position.y +=5;           
            break;

            case SDLK_LEFT:
             for(int i = 0; i<3; i++){
                SDL_BlitSurface(p->left[i], NULL,screen,&p->position);
                SDL_Delay(60);}
            p->position.x -=5;           
            break;

            case SDLK_RIGHT:
             for(int i = 0; i<3; i++){
                SDL_BlitSurface(p->right[i], NULL,screen,&p->position);
                SDL_Delay(60);}
            p->position.x +=5;           
            break;
            
            case SDLK_LCTRL :
            {
                case SDL_MOUSEMOTION:
                {               
                    if(event.motion.x<p->position.x)
                        {
                            for(int i = 0; i<3; i++)
                            {
                              SDL_BlitSurface(p->right[i], NULL,screen,&p->position);
                              SDL_Delay(60);
                            }
                            p->position.x +=5;
                            break;
                        }

                    else if (event.motion.x>p->position.x)
                        { 
                            for(int i = 0; i<3; i++)
                            {
                              SDL_BlitSurface(p->left[i], NULL,screen,&p->position);
                              SDL_Delay(60);
                            }
                            p->position.x -=5;
                            break;
                        }

                    else if (event.motion.y<p->position.y)
                        {
                            for(int i = 0; i<3; i++)
                            {
                              SDL_BlitSurface(p->up[i], NULL,screen,&p->position);
                              SDL_Delay(60);
                            }
                            p->position.y -=5;           
                            break;
                        }

                    else if (event.motion.y>p->position.y)
                        {
                            for(int i = 0; i<3; i++)
                            {
                              SDL_BlitSurface(p->down[i], NULL,screen,&p->position);
                              SDL_Delay(60);
                            }
                            p->position.y +=5;           
                            break;
                        }

                    break;
                }
            }
        }
}         
}