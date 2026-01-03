//
//      vec_types.h  (12/29/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_VEC_TYPES_H
#define _OHM_VEC_TYPES_H


#define VEC4_SIZE 4
#define VEC3_SIZE 3
#define VEC2_SIZE 2


typedef union vec4f
{

        float vec[VEC4_SIZE];


        struct { float x, y, z, w; };

} vec4f;


typedef union vec3f
{

        float vec[VEC3_SIZE];


        struct { float x, y, z; };

} vec3f;


typedef union vec2f
{

        float vec[VEC2_SIZE];


        struct { float x, y; };

} vec2f;


#endif