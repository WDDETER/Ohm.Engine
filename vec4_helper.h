//
//      vec4_helper.h  (12/28/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_VEC4_HELPER_H
#define _OHM_VEC4_HELPER_H


#include <math.h>

#include "vec_types.h"


static inline vec4f vec4_add(vec4f vec1, vec4f vec2) 
{

        return (vec4f)
        {

                .x = vec1.x + vec2.x,
                .y = vec1.y + vec2.y,
                .z = vec1.z + vec2.z,
                .w = vec1.w + vec2.w

        };

}


static inline vec4f vec4_sub(vec4f vec1, vec4f vec2)
{

        return (vec4f)
        {

                .x = vec1.x - vec2.x,
                .y = vec1.y - vec2.y,
                .z = vec1.z - vec2.z,
                .w = vec1.w - vec2.w

        };

}


static inline vec4f vec4_mul_component(vec4f vec1, vec4f vec2)
{

         return (vec4f)
        {

                .x = vec1.x * vec2.x,
                .y = vec1.y * vec2.y,
                .z = vec1.z * vec2.z,
                .w = vec1.w * vec2.w

        };       

}


static inline vec4f vec4_mul_scalar(vec4f vec1, float scalar)
{

         return (vec4f)
        {

                .x = vec1.x * scalar,
                .y = vec1.y * scalar,
                .z = vec1.z * scalar,
                .w = vec1.w * scalar

        };       

}


static inline vec4f vec4_div_component(vec4f vec1, vec4f vec2)
{

         return (vec4f)
        {

                .x = vec1.x / vec2.x,
                .y = vec1.y / vec2.y,
                .z = vec1.z / vec2.z,
                .w = vec1.w / vec2.w

        };       

}


static inline vec4f vec4_div_scalar(vec4f vec1, float scalar)
{

         return (vec4f)
        {

                .x = vec1.x / scalar,
                .y = vec1.y / scalar,
                .z = vec1.z / scalar,
                .w = vec1.w / scalar

        };       

}


static inline float vec4_length(vec4f vec)
{

        return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);

}


static inline float vec4_length_squared(vec4f vec)
{

        return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w;

}


static inline vec4f vec4_unit(vec4f vec)
{

        float length = vec4_length_squared(vec);


        if (length < 0.0001f)
        {

                return vec;

        }

        float inv_length = 1.0f / sqrtf(length);


        return vec4_mul_scalar(vec, inv_length);

}


static inline float vec4_dot(vec4f vec1, vec4f vec2)
{

        return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;

}

static inline vec3f vec4_to_vec3(vec4f vec)
{

        return (vec3f)
        {

                .x = vec.x,
                .y = vec.y,
                .z = vec.z

        };

}


static inline vec2f vec4_to_vec2(vec4f vec)
{

        return (vec2f)
        {

                .x = vec.x,
                .y = vec.y

        };

}


#endif