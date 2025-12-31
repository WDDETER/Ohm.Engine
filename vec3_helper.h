//
//      vec3_helper.h  (12/28/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_VEC3_HELPER_H
#define _OHM_VEC3_HELPER_H


#include <math.h>

#include "vec_types.h"


static inline vec3f vec3f_add(vec3f vec1, vec3f vec2)
{

        return (vec3f)
        {

                .x = vec1.x + vec2.x,
                .y = vec1.y + vec2.y,
                .z = vec1.z + vec2.z

        };

}


static inline vec3f vec3f_sub(vec3f vec1, vec3f vec2)
{

        return (vec3f)
        {

                .x = vec1.x - vec2.x,
                .y = vec1.y - vec2.y,
                .z = vec1.z - vec2.z

        };

}


static inline vec3f vec3f_mul_component(vec3f vec1, vec3f vec2)
{

         return (vec3f)
        {

                .x = vec1.x * vec2.x,
                .y = vec1.y * vec2.y,
                .z = vec1.z * vec2.z

        };       

}


static inline vec3f vec3f_mul_scalar(vec3f vec1, float scalar)
{

         return (vec3f)
        {

                .x = vec1.x * scalar,
                .y = vec1.y * scalar,
                .z = vec1.z * scalar

        };       

}


static inline vec3f vec3f_div_component(vec3f vec1, vec3f vec2)
{

         return (vec3f)
        {

                .x = vec1.x / vec2.x,
                .y = vec1.y / vec2.y,
                .z = vec1.z / vec2.z

        };       

}


static inline vec3f vec3f_div_scalar(vec3f vec1, float scalar)
{

         return (vec3f)
        {

                .x = vec1.x / scalar,
                .y = vec1.y / scalar,
                .z = vec1.z / scalar

        };       

}


static inline float vec3f_length(vec3f vec)
{

        return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);

}


static inline float vec3f_length_squared(vec3f vec)
{

        return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;

}


static inline vec3f vec3f_unit(vec3f vec)
{

        float length = vec3f_length_squared(vec);


        if (length < 0.0001f)
        {

                return vec;

        }

        float inv_length = 1.0f / sqrtf(length);


        return vec3f_mul_scalar(vec, inv_length);

}


static inline float vec3f_dot(vec3f vec1, vec3f vec2)
{

        return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;

}


static inline vec3f vec3f_cross(vec3f vec1, vec3f vec2)
{

        return (vec3f)
        {

                .x = vec1.y * vec2.z - vec1.z * vec2.y,
                .y = vec1.z * vec2.x - vec1.x * vec2.z,
                .z = vec1.x * vec2.y - vec1.y * vec2.x

        };

}


static inline vec4f vec3f_to_vec4f(vec3f vec)
{

        return (vec4f)
        {

                .x = vec.x,
                .y = vec.y,
                .z = vec.z,
                .w = 0.0f

        };

}


static inline vec2f vec3f_to_vec2f(vec3f vec)
{

        return (vec2f)
        {

                .x = vec.x,
                .y = vec.y

        };

}


#endif