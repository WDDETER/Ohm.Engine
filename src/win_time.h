//
//      win_time.h  (1/1/2026)
//      by Jaidev Bormann
//


#ifndef _OHM_WIN_TIME_H
#define _OHM_WIN_TIME_H


#include <windows.h>


struct clock
{

        float           delta_time;


        struct
        {

                LARGE_INTEGER frequency, start_counter, end_counter;

        } rare;

};


struct clock clock_hire();


static inline void clock_tick(struct clock* clock)
{

        QueryPerformanceCounter(&clock->rare.end_counter);


        float elapsed           = (LONGLONG)(clock->rare.end_counter.QuadPart - clock->rare.start_counter.QuadPart);
        clock->delta_time       = elapsed / (float)clock->rare.frequency.QuadPart;


        clock->rare.start_counter = clock->rare.end_counter;

}


#endif