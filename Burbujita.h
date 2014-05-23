#ifndef BURBUJITA_H
#define BURBUJITA_H
#include <SDL/SDL.h>
#include <list>
#include <string>

using namespace std;

class Burbujita
{
    public:
        //Agregamos
    SDL_Surface* surface;
    int x;
    int y;
    bool borrar;
    int puntos;
    string tipo;

    SDL_Surface* screen;


        Burbujita(SDL_Surface* surface,SDL_Surface* screen,int x,int y);
        Burbujita();
        void dibujar();
        void movimiento(int velocidad);
        void logica(int click_x,int click_y,int velocidad);


        virtual ~Burbujita();
    protected:
    private:
};

#endif // BURBUJITA_H
