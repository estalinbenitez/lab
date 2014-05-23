#include "hielo.h"

hielo::hielo(SDL_Surface* surface,SDL_Surface* screen,int x,int y)
{
    this->puntos=0;
this->screen= screen;
this->surface= surface;
this->x=x;
this->y=y;
this->borrar= false;
this->tipo="hielo";
}

hielo::~hielo()
{
    //dtor
}
