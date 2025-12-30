//
//      mat4_helper.c  (12/29/2025)
//      by Jaidev Bormann
//


#include "mat4_helper.h"


// NOTICE!
//
//      any and all functions use row-major.
//


mat4f mat4_mul_mat4(mat4f mat1, mat4f mat2)
{

        return (mat4f)
        {

                .r00 = mat1.r00 * mat2.r00 + mat1.r01 * mat2.r10 + mat1.r02 * mat2.r20 + mat1.r03 * mat2.r30,
                .r01 = mat1.r00 * mat2.r01 + mat1.r01 * mat2.r11 + mat1.r02 * mat2.r21 + mat1.r03 * mat2.r31,
                .r02 = mat1.r00 * mat2.r02 + mat1.r01 * mat2.r12 + mat1.r02 * mat2.r22 + mat1.r03 * mat2.r32,
                .r03 = mat1.r00 * mat2.r03 + mat1.r01 * mat2.r13 + mat1.r02 * mat2.r23 + mat1.r03 * mat2.r33,

                .r10 = mat1.r10 * mat2.r00 + mat1.r11 * mat2.r10 + mat1.r12 * mat2.r20 + mat1.r13 * mat2.r30,
                .r11 = mat1.r10 * mat2.r01 + mat1.r11 * mat2.r11 + mat1.r12 * mat2.r21 + mat1.r13 * mat2.r31,
                .r12 = mat1.r10 * mat2.r02 + mat1.r11 * mat2.r12 + mat1.r12 * mat2.r22 + mat1.r13 * mat2.r32,
                .r13 = mat1.r10 * mat2.r03 + mat1.r11 * mat2.r13 + mat1.r12 * mat2.r23 + mat1.r13 * mat2.r33,

                .r20 = mat1.r20 * mat2.r00 + mat1.r21 * mat2.r10 + mat1.r22 * mat2.r20 + mat1.r23 * mat2.r30,
                .r21 = mat1.r20 * mat2.r01 + mat1.r21 * mat2.r11 + mat1.r22 * mat2.r21 + mat1.r23 * mat2.r31,
                .r22 = mat1.r20 * mat2.r02 + mat1.r21 * mat2.r12 + mat1.r22 * mat2.r22 + mat1.r23 * mat2.r32,
                .r23 = mat1.r20 * mat2.r03 + mat1.r21 * mat2.r13 + mat1.r22 * mat2.r23 + mat1.r23 * mat2.r33,

                .r30 = mat1.r30 * mat2.r00 + mat1.r31 * mat2.r10 + mat1.r32 * mat2.r20 + mat1.r33 * mat2.r30,
                .r31 = mat1.r30 * mat2.r01 + mat1.r31 * mat2.r11 + mat1.r32 * mat2.r21 + mat1.r33 * mat2.r31,
                .r32 = mat1.r30 * mat2.r02 + mat1.r31 * mat2.r12 + mat1.r32 * mat2.r22 + mat1.r33 * mat2.r32,
                .r33 = mat1.r30 * mat2.r03 + mat1.r31 * mat2.r13 + mat1.r32 * mat2.r23 + mat1.r33 * mat2.r33,

        };

}


vec4f vec4_mul_mat4(vec4f vec, mat4f mat)
{

        return (vec4f)
        {

                .x = vec.x * mat.r00 + vec.y * mat.r10 + vec.z * mat.r20 + vec.w * mat.r30,
                .y = vec.x * mat.r01 + vec.y * mat.r11 + vec.z * mat.r21 + vec.w * mat.r31,
                .z = vec.x * mat.r02 + vec.y * mat.r12 + vec.z * mat.r22 + vec.w * mat.r32,
                .w = vec.x * mat.r03 + vec.y * mat.r13 + vec.z * mat.r23 + vec.w * mat.r33,

        };

}