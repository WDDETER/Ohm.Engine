//
//      cam_main.c  (12/29/2025)
//      by Jaidev Bormann
//


#include "cam_main.h"


void camera_lookat(struct camera* camera)
{

        camera->forward = vec3_unit(vec3_sub(camera->target, camera->eye));
        camera->right   = vec3_unit(vec3_cross(camera->forward, camera->up));

        vec3f up = vec3_cross(camera->forward, camera->right);


        camera->view.r00 = camera->right.x;
        camera->view.r01 = camera->right.y;
        camera->view.r02 = camera->right.z;
        camera->view.r03 = 0.0f;

        camera->view.r10 = up.x;
        camera->view.r11 = up.y;
        camera->view.r12 = up.z;
        camera->view.r13 = 0.0f;

        camera->view.r20 = -camera->forward.x;
        camera->view.r21 = -camera->forward.y;
        camera->view.r22 = -camera->forward.z;
        camera->view.r23 = 0.0f;

        camera->view.r30 = -vec3_dot(camera->right, camera->eye);
        camera->view.r31 = -vec3_dot(camera->up, camera->eye);
        camera->view.r32 = vec3_dot(camera->forward, camera->eye);
        camera->view.r33 = 1.0f;

}