//
//      gfx_main.h  (12/28/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_GFX_MAIN_H
#define _OHM_GFX_MAIN_H


#include <stdint.h>

#include "win_main.h"


#define PAINTER_DEF_BIT_COUNT           32
#define PAINTER_DEF_BIT_PLANES          1
#define PAINTER_DEF_BIT_COMPRESSION     BI_RGB

#define BLIT_USAGE                      DIB_RGB_COLORS
#define BLIT_ROP                        SRCCOPY


typedef uint32_t pixel;


union color32
{

        uint32_t argb;


        struct { uint8_t b, g, r, a; };

};


struct painter
{

        pixel*          pixels;
        int             pixels_width, pixels_height, painters_size, painters_sizebytes;


        BITMAPINFO      bit_map;
        DWORD           bit_compression;
        WORD            bit_count, bit_planes;

};


void painter_hire(struct painter* painter);
void painter_fire(struct painter* painter);


static inline void painter_present(struct painter* painter, struct window* window, union color32 clear_color)
{

        StretchDIBits
        (

                window->device_context_handle,
                0, 0, window->width, window->height,
                0, 0, painter->pixels_width, painter->pixels_height,
                painter->pixels, &painter->bit_map,
                BLIT_USAGE, BLIT_ROP

        );


        for (int i = 0; i < painter->painters_size; i++)
        {

                painter->pixels[i] = clear_color.argb;

        }

}


#endif