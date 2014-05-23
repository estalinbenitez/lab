#ifndef BURBUJABOMBA_H
#define BURBUJABOMBA_H
#define BURBUJAAZUL_H
#include "Burbujita.h"
#include <SDL/SDL.h>
#include <list>
using namespace std;



class burbujabomba : public Burbujita
{
    public:
        burbujabomba(SDL_Surface* surface,SDL_Surface* screen,int x,int y);
        virtual ~burbujabomba();
    protected:
    private:
};

#endif // BURBUJABOMBA_H
