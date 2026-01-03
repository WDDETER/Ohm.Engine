//
//      proj_helper.c  (1/1/2026)
//      by Jaidev Bormann
//


#include "proj_helper.h"


mat4f projection_perspective(float fov_rad, float aspect, float near_z, float far_z)
{

        float tan_half_fov = 1.0f / tanf(fov_rad * 0.5f);
        float far_min_near = 1.0f / (far_z - near_z);


        return (mat4f)
        {

                .r00 = tan_half_fov / aspect, .r01 = 0.0f, .r02 = 0.0f, .r03 = 0.0f, 
                .r10 = 0.0f, .r11 = tan_half_fov, .r12 = 0.0f, .r13 = 0.0f,
                .r20 = 0.0f, .r21 = 0.0f, .r22 = -(far_z + near_z) * far_min_near, .r23 = -(2.0f * far_z * near_z) * far_min_near,
                .r30 = 0.0f, .r31 = 0.0f, .r32 = -1.0f, .r33 = 0.0f

        };

}