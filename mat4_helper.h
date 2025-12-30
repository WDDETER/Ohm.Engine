//
//      mat4_helper.h  (12/29/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_MAT4_HELPER_H
#define _OHM_MAT4_HELPER_H


#include "vec4_helper.h"


// NOTICE!
//
//      unlike many other graphic APIs like OpenGL and DirectX, which commonly use column-major
//      matrices. Ohm Engine uses row-major matrices, it's just easier for me.
//


#define MAT4_SIZE 16


typedef union mat4f
{

        float mat[MAT4_SIZE];


        struct
        {

                float r00, r01, r02, r03;
                float r10, r11, r12, r13;
                float r20, r21, r22, r23;
                float r30, r31, r32, r33;

        };

} mat4f;


static inline mat4f mat4_identity(void)
{

        return (mat4f)
        {

                .r00 = 1.0f, .r01 = 0.0f, .r02 = 0.0f, .r03 = 0.0f,
                .r10 = 0.0f, .r11 = 1.0f, .r12 = 0.0f, .r13 = 0.0f,
                .r20 = 0.0f, .r21 = 0.0f, .r22 = 1.0f, .r23 = 0.0f,
                .r30 = 0.0f, .r31 = 0.0f, .r32 = 0.0f, .r33 = 1.0f,

        };

}


static inline mat4f mat4_translate(float x, float y, float z)
{

        return (mat4f)
        {

                .r00 = 1.0f, .r01 = 0.0f, .r02 = 0.0f, .r03 = 0.0f,
                .r10 = 0.0f, .r11 = 1.0f, .r12 = 0.0f, .r13 = 0.0f,
                .r20 = 0.0f, .r21 = 0.0f, .r22 = 1.0f, .r23 = 0.0f,
                .r30 = x, .r31 = y, .r32 = z, .r33 = 1.0f,

        };

}


static inline mat4f mat4_scale(float x, float y, float z)
{

        return (mat4f)
        {

                .r00 = x, .r01 = 0.0f, .r02 = 0.0f, .r03 = 0.0f,
                .r10 = 0.0f, .r11 = y, .r12 = 0.0f, .r13 = 0.0f,
                .r20 = 0.0f, .r21 = 0.0f, .r22 = z, .r23 = 0.0f,
                .r30 = 0.0f, .r31 = 0.0f, .r32 = 0.0f, .r33 = 1.0f,

        };

}


static inline mat4f mat4_rotate_x(float x)
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


static inline mat4f mat4_rotate_y(float y)
{

        float cos = cosf(y);
        float sin = sinf(y);

        return (mat4f)
        {

                .r00 = cos, .r01 = 0.0f, .r02 = sin, .r03 = 0.0f,
                .r10 = 0.0f, .r11 = 1.0f, .r12 = -sin, .r13 = 0.0f,
                .r20 = -sin, .r21 = 0.0f, .r22 = cos, .r23 = 0.0f,
                .r30 = 0.0f, .r31 = 0.0f, .r32 = 0.0f, .r33 = 1.0f,

        };

}


static inline mat4f mat4_rotate_z(float z)
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


mat4f mat4_mul_mat4(mat4f mat1, mat4f mat2);
vec4f vec4_mul_mat4(vec4f vec, mat4f mat);


#endif