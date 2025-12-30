//
//      cam_main.h  (12/29/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_CAM_MAIN_H
#define _OHM_CAM_MAIN_H


#include "mat4_helper.h"
#include "vec3_helper.h"


struct camera
{

        vec3f eye, target;
        vec3f up, right, forward;


        mat4f view;

};


void camera_lookat(struct camera* camera);


#endif