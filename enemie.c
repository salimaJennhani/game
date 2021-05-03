
     /** 
* @file enemie.c 
*/ 

#include <stdio.h>
#include "SDL/SDL.h"
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "struct.h"
/** 
* @brief To initialize the enemy . 
* @param b the background 
* @param url the url of the image  
* @return Enemy
*/

Enemy InitEnemy(Enemy Ennemie,int x, int y)
{
  Ennemie.image[0]=IMG_Load("j1.png");
  Ennemie.image[1]=IMG_Load("j2.png");
  Ennemie.image[2]=IMG_Load("j3.png");

  Ennemie.image2[0]=IMG_Load("j4.png");
  Ennemie.image2[1]=IMG_Load("j5.png");
  Ennemie.image2[2]=IMG_Load("j6.png");

  Ennemie.Hit=IMG_Load("j7.png");

  Ennemie.imageActuel=Ennemie.image[0];
  Ennemie.position.x=x;
  Ennemie.position.y=y;
  Ennemie.positionO=Ennemie.position;
  Ennemie.frame=0;
  Ennemie.direction=0;
  Ennemie.died=0;
  return Ennemie;
}
/*******************************************************************************/
/** 
* @brief To Display the Enemy  . 
* @param Ennemie the Enemy 
* @return Nothing.
*/

void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen)
{
  SDL_BlitSurface(Ennemie.imageActuel,NULL,screen,&Ennemie.position);
  SDL_Flip(screen);
  SDL_Delay(80);
}
/***********************************************************************/
/** 
* @brief To animate the Enemy  . 
* @param Ennemie the Enemy 
* @return Enemy.
*/
Enemy AnimateEnemy(Enemy Ennemie,int stat)
{
  if (Ennemie.frame==2) 
  {
    Ennemie.frame=0;
  }
  else
  Ennemie.frame++;

  if (Ennemie.direction==1)
 	Ennemie.imageActuel=Ennemie.image[Ennemie.frame];
  else if(Ennemie.direction==0)
	Ennemie.imageActuel=Ennemie.image2[Ennemie.frame];

  if(stat==1)
    Ennemie.imageActuel=Ennemie.Hit;
  SDL_Delay(50);
  return Ennemie;

}
/****************************************************************************/
/*

* pour le moment le personnage est sous forme d'un rectangle donc supposé que c'est un evennement .. 
*/
/*void initialiser_evan(hero *evan){
		
	evan->afficher_hero[0]=NULL;
	evan->afficher_hero[1]=NULL;

	evan->afficher_herod[0]=NULL;
	evan->afficher_herod[1]=NULL;

	evan->afficher_hero[0]=IMG_Load("rect.png");
	evan->afficher_hero[1]=IMG_Load("rect.png");

	evan->afficher_herod[0]=IMG_Load("rect.png");
	evan->afficher_herod[1]=IMG_Load("rect.png");

	evan->pos_hero2.x=0;
	evan->pos_hero2.y=0;
	evan->vx =evan->vy = 0.0f;
}

void afficher_evan(hero evan,SDL_Surface *ecran){
	if ((evan.mouvment==1)||(evan.mouvment==9))
		SDL_BlitSurface(evan.afficher_hero[evan.farm],NULL,ecran,&(evan.pos_hero2));
	if (evan.mouvment==2)
		SDL_BlitSurface(evan.afficher_herod[evan.farm],NULL,ecran,&(evan.pos_hero2));
	if (evan.mouvment==3)
		SDL_BlitSurface(evan.afficher_hero[0],NULL,ecran,&(evan.pos_hero2));
}


*/

/********************************************************************************/
/*
/** 
* @brief To move the Enemy  . 
* @param Ennemie the Enemy 
* @return Enemy.
*/
/*Enemy MoveEnemy(Enemy Ennemie,box b,int *stat/*,int mouvment*)
{

int distance;

  if(Ennemie.position.x>=b.x)
    distance=Ennemie.position.x-b.x;
  else
    distance=b.x-Ennemie.position.x;

  if(distance<50)*stat=1;
  else *stat=0;

    if(distance<200)
      {
    if(Ennemie.position.x>=b.x)
          Ennemie.direction=0;
    else
          Ennemie.direction=1;
      }
    else
    { 
	 if(Ennemie.positionO.x+200<=Ennemie.position.x)
          Ennemie.direction=0;

         if(Ennemie.positionO.x-200>=Ennemie.position.x)
	  Ennemie.direction=1;}

	 if(Ennemie.direction==1)
      	  {
            Ennemie.position.x+=4;
          }
      	 if(Ennemie.direction==0)
          {
            Ennemie.position.x-=4;
          }
      //printf("%d\n",distance);
      //printf("%d\n dir",distance);

      /*  if(mouvment==1)
	{
      	 Ennemie.position.x-=5;
      	 Ennemie.positionO.x-=5;
        }
        if (mouvment==2)	
	{
 	 Ennemie.position.x+=5;
      	 Ennemie.positionO.x+=5;
        }
        if ((mouvment==3)&&(b.y>50))
        {
         // Ennemie.position.x-=50;
       // Ennemie.positionO.x-=50;
        }
        
  return Ennemie;

 }
 */
/********************************************************************************/
/** 
* @brief To Died the Enemy  . 
* @param Ennemie the Enemy 
* @return Nothing.
*/
Enemy diedennemie(Enemy Ennemie,int coe)
{

  if (coe==1)
  {

    Ennemie.image[0]=NULL;
    Ennemie.image[1]=NULL;
    Ennemie.image[2]=NULL;
    Ennemie.image2[0]=NULL;
    Ennemie.image2[1]=NULL;
    Ennemie.image2[2]=NULL;
  

  
    Ennemie.Hit=NULL;
    Ennemie.died=1;
  }
  return Ennemie;
}
/******************************************************************************/

/*****************************************************************************/
/*void FreeEspace(Enemy Ennemie,SDL_Surface *ecran)
{
SDL_FreeSurface(Ennemie.image);
SDL_FreeSurface(Ennemie.image2);
SDL_FreeSurface(ecran);
SDL_Quit();

}
*/
