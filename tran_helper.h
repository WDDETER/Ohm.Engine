//
//      tran_helper.h  (12/30/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_TRAN_HELPER_H
#define _OHM_TRAN_HELPER_H


#include "mat4_helper.h"


struct transform
{

        mat4f translate, scale, rotate_x, rotate_y, rotate_z, rotation, transform;

};


static inline mat4f transform_translate(float x, float y, float z)
{

        return (mat4f)
        {

                .r00 = 1.0f, .r01 = 0.0f, .r02 = 0.0f, .r03 = 0.0f,
                .r10 = 0.0f, .r11 = 1.0f, .r12 = 0.0f, .r13 = 0.0f,
                .r20 = 0.0f, .r21 = 0.0f, .r22 = 1.0f, .r23 = 0.0f,
                .r30 = x, .r31 = y, .r32 = z, .r33 = 1.0f,

        };

}


static inline mat4f transform_scale(float x, float y, float z)
{

        return (mat4f)
        {

                .r00 = x, .r01 = 0.0f, .r02 = 0.0f, .r03 = 0.0f,
                .r10 = 0.0f, .r11 = y, .r12 = 0.0f, .r13 = 0.0f,
                .r20 = 0.0f, .r21 = 0.0f, .r22 = z, .r23 = 0.0f,
                .r30 = 0.0f, .r31 = 0.0f, .r32 = 0.0f, .r33 = 1.0f,

        };

}


static inline mat4f transform_rotate_x(float x)
{

        float cos = cosf(x);
        float sin = sinf(x);

        return (mat4f)
        {

                .r00 = 1.0f, .r01 = 0.0f, .r02 = 0.0f, .r03 = 0.0f,
                .r10 = 0.0f, .r11 = cos, .r12 = -sin, .r13 = 0.0f,
                .r20 = 0.0f, .r21 = sin, .r22 = cos, .r23 = 0.0f,
                .r30 = 0.0f, .r31 = 0.0f, .r32 = 0.0f, .r33 = 1.0f,

        };

}


static inline mat4f transform_rotate_y(float y)
{

        float cos = cosf(y);
        float sin = sinf(y);

        return (mat4f)
        {

                .r00 = cos, .r01 = 0.0f, .r02 = sin, .r03 = 0.0f,
                .r10 = 0.0f, .r11 = 1.0f, .r12 = 0.0f, .r13 = 0.0f,
                .r20 = -sin, .r21 = 0.0f, .r22 = cos, .r23 = 0.0f,
                .r30 = 0.0f, .r31 = 0.0f, .r32 = 0.0f, .r33 = 1.0f,

        };

}


static inline mat4f transform_rotate_z(float z)
{

        float cos = cosf(z);
        float sin = sinf(z);

        return (mat4f)
        {

                .r00 = cos, .r01 = -sin, .r02 = 0.0f, .r03 = 0.0f,
                .r10 = sin, .r11 = cos, .r12 = 0.0f, .r13 = 0.0f,
                .r20 = 0.0f, .r21 = 0.0f, .r22 = 1.0f, .r23 = 0.0f,
                .r30 = 0.0f, .r31 = 0.0f, .r32 = 0.0f, .r33 = 1.0f,

        };

}


#endif