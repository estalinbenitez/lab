#include "Burbujita.h"

Burbujita::Burbujita(SDL_Surface* surface,SDL_Surface* screen,int x,int y)
{
this->screen= screen;
this->surface= surface;
this->x=x;
this->y=y;
this->borrar= false;
this->tipo="papa";
}

Burbujita::Burbujita()
{


}

Burbujita::~Burbujita()
{
    //dtor
}


void Burbujita::dibujar(){

 //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( surface, NULL, screen, &offset );

}

void Burbujita::movimiento(int velocidad){

    this->x+=velocidad;



}

void Burbujita::logica(int click_x,int click_y,int velocidad){

    this->movimiento(velocidad);


    if(click_x>=x  && click_x<=x + surface->w
    && click_y>=y && click_y<=y + surface->h)
    {
    //Aqui va todo

    this->borrar = true;

    }





}

