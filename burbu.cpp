#include "burbu.h"

burbu::burbu(SDL_Surface* surface,SDL_Surface* screen,int x,int y)
{
    //ctor

this->screen= screen;
this->surface= surface;
this->x=x;
this->y=y;
this->borrar= false;
this->puntos=0;
}

burbu::~burbu()
{
    //dtor
}
