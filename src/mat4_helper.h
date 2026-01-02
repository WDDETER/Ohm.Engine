//
//      mat4_helper.h  (12/29/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_MAT4_HELPER_H
#define _OHM_MAT4_HELPER_H


#include "vec4_helper.h"
#include "vec3_helper.h"


// NOTICE!
//
//      unlike many other graphic APIs like OpenGL and DirectX, which commonly use column-major
//      matrices. Ohm Engine uses row-major matrices, it's just easier for me.
//


#define MAT4_MULITPLY_ORDER(x, y, z) mat4f_mul_mat4f(x, mat4f_mul_mat4f(y, z));

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


mat4f mat4f_mul_mat4f           (mat4f mat1, mat4f mat2);
vec4f vec4f_mul_mat4f           (vec4f vec, mat4f mat);


static inline mat4f mat4f_identity(void)
{

        return (mat4f)
        {

                .r00 = 1.0f, .r01 = 0.0f, .r02 = 0.0f, .r03 = 0.0f,
                .r10 = 0.0f, .r11 = 1.0f, .r12 = 0.0f, .r13 = 0.0f,
                .r20 = 0.0f, .r21 = 0.0f, .r22 = 1.0f, .r23 = 0.0f,
                .r30 = 0.0f, .r31 = 0.0f, .r32 = 0.0f, .r33 = 1.0f,

        };

}


#endif