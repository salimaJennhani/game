/** 
* @file main.c 
* @brief Testing Program. 
* @author C Team 
* @version 0.1 
* @date Apr 01, 2015 
* 
* Testing program for background scrolling * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "struct.h"


int main()
{
	int stat;
	Enemy e;
	//box b;
	int coe;
	SDL_Surface *screen;
	Mix_Music *music;
	int direction=0;
	int vitesse=0;
	Background b;
	SDL_Event event;
int continuer=1;
    enigme enig;
   /* int ancienne[6],s,r,continuer=1,affiche=0,nouvelleenig=1,temps_actuel=0,temps_pred=0,ligne=0;
    SDL_Event event;
    srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen=NULL;
SDL_Surface *back=NULL;
SDL_Surface *win=NULL;
SDL_Surface *loss=NULL;
win=IMG_Load("win.jpg");
loss=IMG_Load("lose.jpg");
screen=SDL_SetVideoMode (1200,900,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Event event;
SDL_WM_SetCaption("ENIGMEALEA\t1",NULL);
bool running=true;
int reponse=-1;
enigme e;
e=GenEn();*/

SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("impossible d'initialiser sdl :%s",SDL_GetError());
return 1;
}
screen =SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF|SDL_RESIZABLE); //a regler 
if(screen==NULL)
{ 
printf("Unable to set video mod :%s\n",SDL_GetError());
return 1;
}

//SDL_Init(SDL_INIT_VIDEO);
//screen=SDL_SetVideoMode (800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


SDL_WM_SetCaption("background\t1",NULL);

////////////////////////////////////////////////////////////////////
/* enigme GenEn();
  init_enigme(&enig,ancienne);*/


initBack(&b);
e= InitEnemy(e,5500,350);

SDL_EnableKeyRepeat(100,10);////



if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}

music=Mix_LoadMUS("music.mp3");

Mix_PlayMusic(music, -1);


while(continuer)
{
AfficherEnemy(e,screen );

e=AnimateEnemy(e,stat);

//e=MoveEnemy(e,b/*de la position du rectangle*/,&stat);

//coe=Collision_Bounding_Box(&b,&e);

/*e=diedennemie(e,coe);
			if ((e.imageActuel==e.Hit)&&(e.died==0))
			{
				e.Hit=1;
				e.position.x=e.position.x+100;
			}
SDL_Flip(ecran);
*/
    
while(SDL_PollEvent(&event))
	{

        

		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                    direction=1;
                    vitesse=10;     
                break;
                case SDLK_RIGHT:
                    direction=0;
                    vitesse=10;
                break;
                case SDLK_UP:
                    direction=2;
                    vitesse=10;
                break;
                case SDLK_DOWN:
                    direction=3;
                    vitesse=10;
                break ;      
                   

            }
            break;
        case SDL_KEYUP:
            vitesse=0;
        break;    
        }
    } 

scrolling(&b,direction,vitesse);
aficherBack(b,screen);
SDL_Flip(screen);
SDL_Delay(40);
   /* while(nouvelleenig)
   {
    afficher_enigme(&enig,ancienne,"fichier question",&ligne);
    s=solution(ligne);
    continuer=1;
    while(continuer)
    {   
   
       temps_actuel=SDL_GetTicks();
       if(temps_actuel-temps_pred>10000)
       {
          //p->score--;le score diminue
          continuer=0;
          temps_pred=temps_actuel;
       }
       else
          { 
          r=resolution(&affiche);
          if(affiche==1) 
          {
             afficher_resultat(&enig,s,r);
             while(continuer)
             {
	        SDL_PollEvent(&event);
                if(event.type==SDL_QUIT) {
                                            continuer=0;
                                            nouvelleenig=0;
					 }
             }
          }
          }
    }
   }    
    ffree(&enig);
    return EXIT_SUCCESS;
} */
}
}    
