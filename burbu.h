#ifndef BURBU_H
#define BURBU_H
#include "Burbujita.h"
#include <SDL/SDL.h>
#include <list>
using namespace std;



class burbu: public Burbujita
{
    public:

        burbu(SDL_Surface* surface,SDL_Surface* screen,int x,int y);

        virtual ~burbu();
    protected:
    private:
};

#endif // BURBU_H
