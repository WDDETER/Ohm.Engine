//
//      gfx_main.c  (12/28/2025)
//      by Jaidev Bormann
//


#include <stdlib.h>

#include "gfx_main.h"


enum gfx_error painter_hire(struct painter* painter)
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


//*     Might want to refine more later?
//*     Copied from older project.
void painter_line(struct painter* painter, int x1, int y1, int x2, int y2, color32i color)
{

        int diff_x = abs(x2 - x1);
        int side_x = (x1 < x2) ? 1 : -1;
        int diff_y = -abs(y2 - y1);
        int side_y = (y1 < y2) ? 1 : -1;

        int error = diff_x + diff_y;


        while (true) 
        {

                painter->pixels[y1 * painter->pixels_width + x1] = (pixel)color.argb;


                int error_mul_2 = error * 2;

                if (error_mul_2 >= diff_y)
                {

                        if (x1 == x2) break;

                        error += diff_y;
                        x1 += side_x;

                }

                if (error_mul_2 <= diff_x)
                {

                        if (y1 == y2) break;


                        error += diff_x;

                        y1 += side_y;

                }

        }

}