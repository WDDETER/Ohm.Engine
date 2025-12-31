//
//      proj_helper.h  (12/29/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_PROJ_HELPER_H
#define _OHM_PROJ_HELPER_H


#include "gfx_main.h"
#include "mat4_helper.h"


struct projf
{

        float fov_rad, aspect, near_z, far_z;

        mat4f perspective;

};


static inline vec4f projection_screenspace(vec4f position, int width, int height)
{

        int width_div2  = width >> 1;
        int height_div2 = height >> 1;


        return (vec4f)
        {

                .x = (position.x + 1.0f) * width_div2,
                .y = (position.y + 1.0f) * height_div2,
                .z = position.z,
                .w = position.w

        };

}


#endif