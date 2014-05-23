/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Burbujita.h"
#include "burbu.h"
#include "hielo.h"
#include "burbujaazul.h"
#include "burbujabomba.h"
#include <list>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "Timer.h"
using namespace std;
//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 30;
const int FRAMES_PER_SECOND = 190;

//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *up = NULL;

SDL_Surface *down = NULL;
SDL_Surface *left = NULL;
SDL_Surface *right = NULL;
SDL_Surface *screen = NULL;

SDL_Surface *puntos = NULL;
SDL_Surface *seconds = NULL;

//The event structure
SDL_Event event;

//The font
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = { 0, 0, 0 };

SDL_Surface *load_image( std::string filename )
{

    return IMG_Load(filename.c_str());

}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Press an Arrow Key", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //EN ESTA PARTE COLOCO LA IMAGEN DE FONDO DEL JUEGO
    background = load_image( "background.png" );

    //Open the font
    font = TTF_OpenFont( "uhura2239.ttf", 50 );

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( puntos );



    //Close the font
    TTF_CloseFont( font );

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}



//EL jUEGO


void Finn(){

SDL_Surface* gane=load_image("gano.png");

    int frame=0;
    bool quit = false;
    SDL_Surface* bienvenida=load_image("inicio.png");
    while( quit == false)
    {
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }


            if(event.type== SDL_KEYDOWN && event.key.keysym.sym== SDLK_RETURN)
            {
                quit = true;

            }
        }



        //lo del timer



        apply_surface(0,0,gane,screen);
        if(SDL_Flip(screen)==-1)
        {
            return;
        }

    }

}

void elJuego()
{


    bool cap = true;
    Timer fps;

    int velocidad=1;
    int score=0;


     //The timer starting time
    Uint32 start = 20;
    //The timer start/stop flag
    bool running = true;

    //Start the timer
    start = 20;


    list<Burbujita*>burbujas;
    srand(time(NULL));
    int frame=0;

    int framess=0;

    bool quit =false;
    while( quit == false )
    {
    fps.start();

    //esto es del taimer

    //hasta aqui


        //hacemos que las burbujitas salgan ah lazar en varias posiciones y verificamos que la velocidad este = 1
        //ya que esto me sirve para las burbujas de hielo

        framess++;

        if(framess%200==0 && velocidad==1)
        {
            burbujas.push_back(new burbujaazul(load_image("GAN.png"),screen,0, rand() %SCREEN_HEIGHT));


        }
        if(framess%350==0 && velocidad==1)
        {
            burbujas.push_back(new burbujabomba(load_image("Bom.png"),screen,0, rand() %SCREEN_HEIGHT));


        }

        if(framess%400==0 && velocidad==1)
        {
            burbujas.push_back(new hielo(load_image("HIE.png"),screen,0, rand() %SCREEN_HEIGHT));


        }

        int click_x=-1;
        int click_y=-1;

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
        //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //If s was pressed
                if( event.key.keysym.sym == SDLK_s )
                {
                    //If the timer is running
                    if( running == true )
                    {
                        //Stop the timer
                        running = false;
                        start = 0;
                    }
                    else
                    {
                        //Start the timer
                        running = true;
                        start = SDL_GetTicks();
                    }
                }
            }

            //prueba del contador de tiempo

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }

            //esto cierra el sistema al presionar el botton izquierdo del mouse
            if(event.type== SDL_MOUSEBUTTONDOWN)
            {

                if(event.button.button== SDL_BUTTON_LEFT)
                {

                    //
                    click_x= event.button.x;
                    click_y=event.button.y;

                }


            }
            if(event.type== SDL_KEYDOWN && event.key.keysym.sym== SDLK_ESCAPE)
            {

                quit = true;

            }




        }

        //Apply the background
        apply_surface( 0, 0, background, screen );
        //lo del timer




        //Get the keystates
        Uint8 *keystates = SDL_GetKeyState( NULL );


        //EN ESTA LINEA AGREGAMOS LA DISQUE BURBUJA y hacemos que se mueva y la borramos de la ram y de la lista
        list<Burbujita*>::iterator i=burbujas.begin();
        while(i!=burbujas.end())
        {

            if((*i)->borrar)
            {
            if((*i)->tipo=="hielo"){
                velocidad=0;

            }

                Burbujita*temp= (*i);
                score+=temp->puntos;
                i = burbujas.erase(i);
                delete temp;

            }
            else
            {

                (*i)->dibujar();
                (*i)->logica(click_x,click_y,velocidad);
            }
            i++;
        }

        if(score>10)
        {
            Finn();

            quit = true;

        }

        //********+
    if(frame%400==0){
        velocidad=1;

    }

//Hasta aqui llega el juego
        if( running == true )
        {
            //The timer's time as a string
            std::stringstream time;

            //Convert the timer's time to a string
            time << "Timer: " << SDL_GetTicks() - start;

            //Render the time surface
            seconds = TTF_RenderText_Solid( font, time.str().c_str(), textColor );

            //Apply the time surface
            apply_surface( ( SCREEN_WIDTH - seconds->w ) / 100, 0, seconds, screen );

            //Free the time surface
            SDL_FreeSurface( seconds );
        }


        //esto es para mostrar un texto en pantalla del score y la cantidaad de pelotitas reventadas
        std::stringstream  SCORE;
        SCORE<< "SCORE: " << score;
        puntos = TTF_RenderText_Solid( font, SCORE.str().c_str(), textColor);

        apply_surface(400,0,puntos,screen);




        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return;
        }

           //Increment the frame counter
        frame++;

        //If we want to cap the frame rate
        if( ( cap == true ) && ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) )
        {
            //Sleep the remaining frame time
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }

    }


}

void menu()
{

    int frame=0;
    bool quit = false;
    bool running = true;
    SDL_Surface* menu_bg=load_image("instrucciones.png");
    while( quit == false)
    {
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
            if(event.type== SDL_KEYDOWN && event.key.keysym.sym== SDLK_RETURN)
            {

                elJuego();

            }

            //Error aqui al presionar esc
            if(event.type== SDL_KEYDOWN && event.key.keysym.sym== SDLK_ESCAPE)
            {
                quit = true;

            }

        }



        //lo del timer



        apply_surface(0,0,menu_bg,screen);
        if(SDL_Flip(screen)==-1)
        {
            return;
        }

    }
}

void bienvenida(){


    int frame=0;
    bool quit = false;
    SDL_Surface* bienvenida=load_image("inicio.png");
    while( quit == false)
    {
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
            if(event.type== SDL_KEYDOWN && event.key.keysym.sym== SDLK_SPACE)
            {

                menu();

            }

            if(event.type== SDL_KEYDOWN && event.key.keysym.sym== SDLK_RETURN)
            {
                quit = true;

            }
        }



        //lo del timer



        apply_surface(0,0,bienvenida,screen);
        if(SDL_Flip(screen)==-1)
        {
            return;
        }

    }

}









int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    //Render the text



    Burbujita *b = new Burbujita(load_image("burbuja.png"),screen,0,0);

    //Agregamos las burbujitas ah una list

    //JUego
    bienvenida();

    //Clean up
    clean_up();

    return 0;
}
