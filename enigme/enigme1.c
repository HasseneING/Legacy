#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define LARGEUR 1300
#define HAUTEUR 705

SDL_Surface* screen=NULL;
SDL_Rect screenrect={0,0,0,0};
SDL_Surface* bg=NULL;
SDL_Rect bgrect={0,0,0,0};
SDL_Surface* ques=NULL;
SDL_Rect quesrect={0,0,230,58};
SDL_Surface* yes1=NULL;
SDL_Rect yes1rect={0,50,230,58};
SDL_Surface* no1=NULL;
SDL_Rect no1rect={0,100,230,58};
SDL_Surface* yes2=NULL;
SDL_Surface* no2=NULL;
SDL_Event event={0};
int main()
{
int eng=1;
int now=0;
int ex=0;
int pfps=5;
int dt=0;
int etat=4;
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
//images
bg=IMG_Load("bg.png");
SDL_GetClipRect(bg,&bgrect);
ques=IMG_Load("question.png");
yes1=IMG_Load("yes1.png");
no1=IMG_Load("no1.png");
yes2=IMG_Load("yes2.png");
no2=IMG_Load("no2.png");
screen=SDL_SetVideoMode(bg->w,bg->h,bpp,SDL_HWSURFACE);
SDL_WM_SetCaption("bg",NULL);
while(eng)
{


now=SDL_GetTicks();
dt=now-ex;
if(dt>=pfps)
{
//update
SDL_BlitSurface(bg,NULL,screen,&bgrect);
SDL_BlitSurface(ques,NULL,screen,&quesrect);
SDL_BlitSurface(yes1,NULL,screen,&yes1rect);
SDL_BlitSurface(no1,NULL,screen,&no1rect);
if(etat==2)
SDL_BlitSurface(yes2,NULL,screen,&yes1rect);
if(etat==1)
SDL_BlitSurface(no2,NULL,screen,&no1rect);
if(etat==0)
etat=4;
if(etat==5)
etat=1;
SDL_PollEvent(&event);
switch(event.type)
{case SDL_QUIT:
{
    eng=0;
  }
break;
case SDL_KEYDOWN:
 if(event.key.keysym.sym==SDLK_DOWN)

  {
etat--;
SDL_Delay(50);
  }
 if(event.key.keysym.sym==SDLK_UP)

  {
etat++;
SDL_Delay(50);
  }
break;
}




SDL_Flip(screen);
ex=now;
}else
 SDL_Delay(pfps-dt);
}
SDL_FreeSurface(ques);
SDL_FreeSurface(yes1);
SDL_FreeSurface(no1);
SDL_FreeSurface(yes2);
SDL_FreeSurface(no2);
SDL_Quit();
return 0;
}
