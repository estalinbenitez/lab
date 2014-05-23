#ifndef BURBUJAAZUL_H
#define BURBUJAAZUL_H
#include "Burbujita.h"
#include <SDL/SDL.h>
#include <list>
using namespace std;



class burbujaazul : public Burbujita
{
    public:
        burbujaazul(SDL_Surface* surface,SDL_Surface* screen,int x,int y);
        virtual ~burbujaazul();
    protected:
    private:
};

#endif // BURBUJAAZUL_H
