#ifndef HIELO_H
#define HIELO_H
#include "Burbujita.h"
#include <SDL/SDL.h>
#include <list>
using namespace std;

class hielo : public Burbujita
{
    public:
        hielo(SDL_Surface* surface,SDL_Surface* screen,int x,int y);
        virtual ~hielo();
    protected:
    private:
};

#endif // HIELO_H
