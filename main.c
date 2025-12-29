//
//      main.c  (12/28/2025)
//      by Jaidev Bormann
//


#include "win_main.h"
#include "gfx_main.h"


int main(void)
{
        
        struct window window    = { 0 };

        window.style            = (WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE);

        window.class_name       = WINDOW_DEF_CLASS_NAME;
        window.name             = WINDOW_DEF_NAME;

        window.width            = WINDOW_DEF_WIDTH;
        window.height           = WINDOW_DEF_HEIGHT;

        window.procedure        = window_procedure;

        window_center   (&window);
        window_hire     (&window);


        struct painter painter  = { 0 };
        
        painter.pixels_width    = 320;
        painter.pixels_height   = 240;

        painter.bit_compression = PAINTER_DEF_BIT_COMPRESSION;
        painter.bit_count       = PAINTER_DEF_BIT_COUNT;
        painter.bit_planes      = PAINTER_DEF_BIT_PLANES;

        painter_hire(&painter);


        union color32 color = { 0 };
        

        while (window.is_running)
        {

                window_pump(&window, 0, 0);


                painter_present(&painter, &window, color);

        }


        painter_fire    (&painter);
        window_fire     (&window);


        return 0;

}