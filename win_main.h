//
//      win_main.h  (12/28/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_WIN_MAIN_H
#define _OHM_WIN_MAIN_H


#include <windows.h>
#include <stdbool.h>

#include "win_error.h"


#define WINDOW_DEF_NAME         "Ohm Engine: Windows Application"
#define WINDOW_DEF_CLASS_NAME   "Ohm Engine: Windows Class"

#define WINDOW_DEF_WIDTH        640
#define WINDOW_DEF_HEIGHT       480


struct window
{

        const char*     name;
        const char*     class_name;
        int             x, y, width, height;


        bool            is_running;


        HWND            handle;
        HINSTANCE       instance_handle;
        HDC             device_context_handle;


        WNDPROC         procedure;
        WNDCLASSEX      class;


        MSG             message;


        DWORD           style;


        struct
        {

                HWND    parent_handle;
                HMENU   menu_handle;


                LPVOID  user_data;


                DWORD   style_ex;


        } rare;

};


enum window_error       window_hire     (struct window* window);
void                    window_fire     (struct window* window);
void                    window_center   (struct window* window);

LRESULT CALLBACK window_procedure(HWND handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter);


static inline void window_pump(struct window* window, unsigned int message_filter_min, unsigned int message_filter_max)
{

        while (PeekMessage(&window->message, NULL, message_filter_min, message_filter_max, PM_REMOVE))
        {

                if (window->message.message == WM_QUIT) window->is_running = false;


                TranslateMessage(&window->message);
                DispatchMessage (&window->message);

        }

}


#endif