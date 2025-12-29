//
//      gfx_main.c  (12/28/2025)
//      by Jaidev Bormann
//


#include <stdlib.h>

#include "gfx_main.h"
#include "gfx_error.h"


enum painter_error painter_hire(struct painter* painter)
{

        if (!painter)
                return PAINTER_NULL_POINTER;


        painter->bit_map.bmiHeader.biSize               = sizeof(BITMAPINFOHEADER);
        painter->bit_map.bmiHeader.biCompression        = painter->bit_compression;
        painter->bit_map.bmiHeader.biBitCount           = painter->bit_count;
        painter->bit_map.bmiHeader.biPlanes             = painter->bit_planes;
        painter->bit_map.bmiHeader.biWidth              = painter->pixels_width;
        painter->bit_map.bmiHeader.biHeight             = painter->pixels_height;


        painter->painters_size = painter->pixels_width * painter->pixels_height;
        painter->painters_sizebytes = painter->painters_size * sizeof(pixel);

        painter->pixels = (pixel*)malloc(painter->painters_sizebytes);

        if (!painter->pixels)
                return PAINTER_FAILED_ALLOCATION;


        return PAINTER_HEALTHY;

}


void painter_fire(struct painter* painter)
{

        free(painter->pixels);

        painter->pixels = NULL;

}