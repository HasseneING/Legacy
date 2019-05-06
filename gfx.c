#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <math.h>
 
int main()
{
    
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface* screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_Surface* image = IMG_Load("/home/elbeuuf/Desktop/gfx/corombo.png");
    int run = 1;
    SDL_Event event;
    int angle=0;
    float zoom=1.0;

    while(run == 1)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
               {run = 0;
                break;}

        
            case SDL_KEYDOWN:
		         switch(event.key.keysym.sym)
		          {               
		              case SDLK_ESCAPE:
                         {run = 0;break;}
                      case SDLK_SPACE :
                         {angle+=1;zoom+=0.0005;break;}

		          }
        }
        
        SDL_Surface* roto = rotozoomSurface(image,angle,zoom,0);
        SDL_SetColorKey(roto,SDL_SRCCOLORKEY, SDL_MapRGB(roto->format, 255, 255, 255));

        SDL_Rect rec={200,200,0,0};
        rec.x-=roto->w/2-image->w/2;
        rec.y-=roto->h/2-image->h/2;

        SDL_FillRect(screen, NULL,0);
        SDL_BlitSurface(roto,NULL,screen,&rec);
        SDL_FreeSurface(roto);
        SDL_Flip(screen);
    }
 
    SDL_FreeSurface(screen);
    SDL_FreeSurface(image);
    SDL_Quit();
 
    return 0;
}

