#include "burbujaazul.h"

burbujaazul::burbujaazul(SDL_Surface* surface,SDL_Surface* screen,int x,int y)
{
    //ctor
this->puntos=1;
this->screen= screen;
this->surface= surface;
this->x=x;
this->y=y;
this->borrar= false;
this->tipo="Buena";
}

burbujaazul::~burbujaazul()
{
    //dtor
}
