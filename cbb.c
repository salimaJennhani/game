/** 
* @file main.c 
* @brief Testing Program. 
* @author Jenhani  Salima
* @version 0.1 
* @date Apr 26, 2021
* 
* Testing program for "colision parfaite" * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
void init_box(box *b)
{
b->x=698;
b->y=600;
b->w=60;
b->h=75;
}
int Collision_Bounding_Box(box *b,Enemy *e) 
/*
int collision(box *b,Ennemi *e)
{
b->x=698;
b->y=600;
b->w=60;
b->h=75;

*/
{


	int colli =1 ; 
	if ((b->x<((e->position.x)+10))&&(b->y+10<=((e->position.y)+85))&&((b->w+110)>((e->position.x)+30))&&((b->h+250)>=(e->position.y)))
	{
		colli=0 ; 
	}
	//printf ("%d \n",e.position.x);
	return colli ; 

}
