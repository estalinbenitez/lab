#ifndef TIMER_H
#define TIMER_H
#include <SDL/SDL.h>
#include <list>
#include <string>

using namespace std;


class Timer
{
    public:

    int startTicks;
    int pausedTicks;
    bool paused;
    bool started;



        Timer();
         void start();
        void stop();
        void pause();
        void unpause();
        int get_ticks();
        bool is_started();
    bool is_paused();

        virtual ~Timer();
    protected:
    private:
};

#endif // TIMER_H
