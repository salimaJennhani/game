 #ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <unistd.h>
//////////////////////////////////////////////////
/** 
* @struct Background 
* @brief struct for background 
*/ 

typedef struct Background
	{
        SDL_Surface *bg;
        SDL_Rect camera;
	}Background;

void initBack(Background * b) ;
void aficherBack(Background b, SDL_Surface * screen);
void scrolling (Background * b, int direction, int pasAvancement); 
/////////////////////////////////////////////////////
/** 
* @struct ENEMY 
* @brief struct for Enemy
*/ 

typedef struct Enemy
{
  SDL_Surface *image[3];
  SDL_Surface *image2[3];
  SDL_Surface *Hit;
  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  int frame;
  int direction;
  int died;

}Enemy;
//////////////////////////////////////////////////
typedef struct box
{
int x;
int y;
int w;
int h;
}box;
///////////////////////////////////////////////////////
/** 
* @struct ENIGME 
* @brief struct for Enigme avec Ficher 
*/ 

typedef struct
{
    SDL_Surface *fenetre_enigme;
    SDL_Surface *image;
    SDL_Surface *texte;
    TTF_Font *police;
    SDL_Rect posim,post;
}enigme1;

////////////////////////////////////////////////////////
/** 
* @struct ENIGME 
* @brief struct for Enigme SANS Ficher 
*/ 

typedef struct 
{
    char question[50];
    char rp1[50],rp2[50],rp3[50];
    int sol;
}enigme;

///////////////////////////////////////////////////////
	//void init_box(box *b);
	void afficher_evan(box b,SDL_Surface *ecran);
	Enemy InitEnemy(Enemy Ennemie,int x, int y);
	void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen);
	Enemy AnimateEnemy(Enemy Ennemie,int stat);
	//Enemy MoveEnemy(Enemy Ennemie,box b,int *stat/*,int mouvment*/);
	void init_box(box *b);
	int Collision_Bounding_Box(box *b ,Enemy *e);
	Enemy diedennemie(Enemy Ennemie,int coe);
	//void FreeEspace(Enemy ennemie,SDL_Surface *ecran);
	extern Enemy Ennemie;
	void init_enigme(enigme *enig,int ancienne[]);
	void remplir_fichier(char fichier_question[]);
	void afficher_enigme(enigme *enig,int *ancienne,char fichier_question[],int *ligne);
	int solution(int q);
	int resolution(int *affiche);
	void afficher_resultat(enigme *enig,int solution,int resolution);
	void ffree(enigme *enig);

enigme GenEn();
void AffEn(enigme *en, SDL_Surface * ecran) ;
void ffree(enigme *enig) ;
#endif
