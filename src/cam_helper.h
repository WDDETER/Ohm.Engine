//
//      cam_helper.h  (12/29/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_CAM_HELPER_H
#define _OHM_CAM_HELPER_H


#include "mat4_helper.h"
#include "vec_types.h"


struct camera
{

        vec3f eye, target, up, right, forward, angles;

        mat4f view;

};


mat4f   camera_lookat(vec3f* forward, vec3f* right, vec3f up, vec3f eye, vec3f target);
vec3f   camera_angles(vec3f* forward, vec3f* right, vec3f up, vec3f angles);


#endif