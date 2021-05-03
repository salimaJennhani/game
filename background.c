/** 
* @file main.c 
* @brief Testing Program. 
* @author C Team 
* @version 0.1 
* @date Apr 01, 2015 
* 
* Testing program for background scrolling * 
*/#include "struct.h"
/**
* @brief To initialize the background b .
* @param b the background
* @param url the url of the image
* @return Nothing
*/
void initBack(Background * b) {
    b->bg=IMG_Load("back.png");
    b->camera.x=400;
    b->camera.y=400;
    b->camera.h=600;
    b->camera.w=800;
}

/**
* @brief To show the background b .
* @param scren the screen
* @param b the background
* @return Nothing
*/
void aficherBack(Background b, SDL_Surface * screen){
    SDL_BlitSurface(b.bg,&b.camera,screen,NULL);
}

/**
* @brief To scroll the background to the right .
* @param b the background
* @return Nothing
*/
void scrolling (Background * b, int direction, int pasAvancement){
    switch (direction)
    {
    case 0:
        b->camera.x += pasAvancement ;
        break;
    case 1:
        b->camera.x -= pasAvancement;
        break;

    case 2:
        b->camera.y -= pasAvancement;
        break;
    case 3:
        b->camera.y += pasAvancement;
        break;        
    
    }
}
