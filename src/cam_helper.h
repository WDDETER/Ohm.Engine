//
//      cam_helper.h  (12/29/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_CAM_HELPER_H
#define _OHM_CAM_HELPER_H


#include "mat4_helper.h"
#include "vec_types.h"


struct camf
{

        vec3f eye, target, up, right, forward;

        mat4f view;

};


#endif