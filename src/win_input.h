//
//      win_input  (12/31/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_WIN_INPUT_H
#define _OHM_WIN_INPUT_H


#include <windows.h>
#include <stdbool.h>


#define INPUT_HELD_MASK         0x8000
#define INPUT_TAPPED_MASK       0x0001


static inline bool window_key_held(int vk_code)
{

        return GetAsyncKeyState(vk_code) & INPUT_HELD_MASK;

}


static inline bool window_key_tapped(int vk_code)
{

        return GetAsyncKeyState(vk_code) & INPUT_TAPPED_MASK;

}


#endif