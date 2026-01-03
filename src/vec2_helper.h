//
//      vec2_helper.h  (12/28/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_VEC2_HELPER_H
#define _OHM_VEC2_HELPER_H


#include <math.h>

#include "vec_types.h"


static inline vec2f vec2f_add(vec2f vec1, vec2f vec2)
{

        return (vec2f)
        {

                .x = vec1.x + vec2.x,
                .y = vec1.y + vec2.y

        };

}


static inline vec2f vec2f_sub(vec2f vec1, vec2f vec2)
{

        return (vec2f)
        {

                .x = vec1.x - vec2.x,
                .y = vec1.y - vec2.y

        };

}


static inline vec2f vec2f_mul_component(vec2f vec1, vec2f vec2)
{

         return (vec2f)
        {

                .x = vec1.x * vec2.x,
                .y = vec1.y * vec2.y

        };       

}


static inline vec2f vec2f_mul_scalar(vec2f vec1, float scalar)
{

         return (vec2f)
        {

                .x = vec1.x * scalar,
                .y = vec1.y * scalar

        };       

}


static inline vec2f vec2f_div_component(vec2f vec1, vec2f vec2)
{

         return (vec2f)
        {

                .x = vec1.x / vec2.x,
                .y = vec1.y / vec2.y

        };       

}


static inline vec2f vec2f_div_scalar(vec2f vec1, float scalar)
{

         return (vec2f)
        {

                .x = vec1.x / scalar,
                .y = vec1.y / scalar

        };       

}


static inline float vec2f_length(vec2f vec)
{

        return sqrtf(vec.x * vec.x + vec.y * vec.y);

}


static inline float vec2f_length_squared(vec2f vec)
{

        return vec.x * vec.x + vec.y * vec.y;

}


static inline vec2f vec2f_unit(vec2f vec)
{

        float length = vec2f_length_squared(vec);


        if (length < 0.0001f)
        {

                return vec;

        }

        float inv_length = 1.0f / sqrtf(length);


        return vec2f_mul_scalar(vec, inv_length);

}


static inline float vec2f_dot(vec2f vec1, vec2f vec2)
{

        return vec1.x * vec2.x + vec1.y * vec2.y;

}


static inline float vec2f_cross(vec2f vec1, vec2f vec2)
{

        return vec1.x * vec2.y - vec1.y * vec2.x;

}


static inline vec4f vec2f_to_vec4f(vec2f vec)
{

        return (vec4f)
        {

                .x = vec.x,
                .y = vec.y,
                .z = 0.0f,
                .w = 0.0f

        };

}


static inline vec3f vec2f_to_vec3f(vec2f vec)
{

        return (vec3f)
        {

                .x = vec.x,
                .y = vec.y,
                .z = 0.0f

        };

}


#endif