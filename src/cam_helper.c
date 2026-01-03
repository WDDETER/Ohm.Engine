//
//      cam_helper.c  (1/1/2026)
//      by Jaidev Bormann
//


#include "cam_helper.h"


mat4f camera_lookat(vec3f* forward, vec3f* right, vec3f up, vec3f eye, vec3f target)
{

        *forward = vec3f_unit(vec3f_sub(target, eye));
        *right   = vec3f_unit(vec3f_cross(*forward, up));

        vec3f up_new = vec3f_cross(*forward, *right);


        return (mat4f)
        {

                .r00 = right->x, .r01 = right->y, .r02 = right->z, .r03 = 0.0f,
                .r10 = up_new.x, .r11 = up_new.y, .r12 = up_new.z, .r13 = 0.0f,
                .r20 = -forward->x, .r21 = -forward->y, .r22 = -forward->z, .r23 = 0.0f,
                .r30 = -vec3f_dot(*right, eye), .r31 = -vec3f_dot(up_new, eye), .r32 = vec3f_dot(*forward, eye), .r33 = 1.0f

        };

}


vec3f camera_angles(vec3f* forward, vec3f* right, vec3f up, vec3f angles)
{

        forward->x      = cosf(angles.y) * sinf(angles.x);
        forward->y      = sinf(angles.y);
        forward->z      = cosf(angles.y) * cosf(angles.x);      
        *right          = vec3f_unit(vec3f_cross(*forward, up));

        vec3f up_new = vec3f_cross(*forward, *right);


        return up_new;

}