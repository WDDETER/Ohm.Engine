//
//      win_time.c  (1/1/2026)
//      by Jaidev Bormann
//


#include "win_time.h"


struct clock clock_hire()
{

        struct clock clock = { 0 };


        QueryPerformanceFrequency       (&clock.rare.frequency);
        QueryPerformanceCounter         (&clock.rare.start_counter);


        return clock;

}