//
//      proj_main.h  (12/29/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_PROJ_MAIN_H
#define _OHM_PROJ_MAIN_H


#include "gfx_main.h"
#include "mat4_helper.h"


struct projection
{

        float fov_radians, aspect;
        float near_z, far_z;


        mat4f projection;

};


static inline void projection_perspective(struct projection* projection)
{

        float tan_half_fov = 1.0f / tanf(projection->fov_radians * 0.5f);
        float far_min_near = 1.0f / (projection->far_z - projection->near_z);


        projection->projection.r00 = tan_half_fov / projection->aspect;
        projection->projection.r01 = 0.0f;
        projection->projection.r02 = 0.0f;
        projection->projection.r03 = 0.0f;

        projection->projection.r10 = 0.0f;
        projection->projection.r11 = tan_half_fov;
        projection->projection.r12 = 0.0f;
        projection->projection.r13 = 0.0f;

        projection->projection.r20 = 0.0f;
        projection->projection.r21 = 0.0f;
        projection->projection.r22 = -(projection->far_z + projection->near_z) * far_min_near;
        projection->projection.r23 = -(2.0f * projection->far_z * projection->near_z) * far_min_near;

        projection->projection.r30 = 0.0f;
        projection->projection.r31 = 0.0f;
        projection->projection.r32 = -1.0f;
        projection->projection.r33 = 0.0f;

}


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