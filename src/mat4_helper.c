//
//      mat4_helper.c  (12/29/2025)
//      by Jaidev Bormann
//


#include "mat4_helper.h"


// NOTICE!
//
//      any and all functions use row-major.
//


mat4f mat4f_mul_mat4f(mat4f mat1, mat4f mat2)
{

        return (mat4f)
        {

                .r00 = mat1.r00 * mat2.r00 + mat1.r01 * mat2.r10 + mat1.r02 * mat2.r20 + mat1.r03 * mat2.r30,
                .r01 = mat1.r00 * mat2.r01 + mat1.r01 * mat2.r11 + mat1.r02 * mat2.r21 + mat1.r03 * mat2.r31,
                .r02 = mat1.r00 * mat2.r02 + mat1.r01 * mat2.r12 + mat1.r02 * mat2.r22 + mat1.r03 * mat2.r32,
                .r03 = mat1.r00 * mat2.r03 + mat1.r01 * mat2.r13 + mat1.r02 * mat2.r23 + mat1.r03 * mat2.r33,

                .r10 = mat1.r10 * mat2.r00 + mat1.r11 * mat2.r10 + mat1.r12 * mat2.r20 + mat1.r13 * mat2.r30,
                .r11 = mat1.r10 * mat2.r01 + mat1.r11 * mat2.r11 + mat1.r12 * mat2.r21 + mat1.r13 * mat2.r31,
                .r12 = mat1.r10 * mat2.r02 + mat1.r11 * mat2.r12 + mat1.r12 * mat2.r22 + mat1.r13 * mat2.r32,
                .r13 = mat1.r10 * mat2.r03 + mat1.r11 * mat2.r13 + mat1.r12 * mat2.r23 + mat1.r13 * mat2.r33,

                .r20 = mat1.r20 * mat2.r00 + mat1.r21 * mat2.r10 + mat1.r22 * mat2.r20 + mat1.r23 * mat2.r30,
                .r21 = mat1.r20 * mat2.r01 + mat1.r21 * mat2.r11 + mat1.r22 * mat2.r21 + mat1.r23 * mat2.r31,
                .r22 = mat1.r20 * mat2.r02 + mat1.r21 * mat2.r12 + mat1.r22 * mat2.r22 + mat1.r23 * mat2.r32,
                .r23 = mat1.r20 * mat2.r03 + mat1.r21 * mat2.r13 + mat1.r22 * mat2.r23 + mat1.r23 * mat2.r33,

                .r30 = mat1.r30 * mat2.r00 + mat1.r31 * mat2.r10 + mat1.r32 * mat2.r20 + mat1.r33 * mat2.r30,
                .r31 = mat1.r30 * mat2.r01 + mat1.r31 * mat2.r11 + mat1.r32 * mat2.r21 + mat1.r33 * mat2.r31,
                .r32 = mat1.r30 * mat2.r02 + mat1.r31 * mat2.r12 + mat1.r32 * mat2.r22 + mat1.r33 * mat2.r32,
                .r33 = mat1.r30 * mat2.r03 + mat1.r31 * mat2.r13 + mat1.r32 * mat2.r23 + mat1.r33 * mat2.r33,

        };

}


mat4f mat4f_cam_lookat(vec3f forward, vec3f right, vec3f up, vec3f eye, vec3f target)
{

        forward = vec3f_unit(vec3f_sub(target, eye));
        right   = vec3f_unit(vec3f_cross(forward, up));

        vec3f up_new = vec3f_cross(forward, right);


        return (mat4f)
        {

                .r00 = right.x, .r01 = right.y, .r02 = right.z, .r03 = 0.0f,
                .r10 = up_new.x, .r11 = up_new.y, .r12 = up_new.z, .r13 = 0.0f,
                .r20 = -forward.x, .r21 = -forward.y, .r22 = -forward.z, .r23 = 0.0f,
                .r30 = -vec3f_dot(right, eye), .r31 = -vec3f_dot(up_new, eye), .r32 = vec3f_dot(forward, eye), .r33 = 1.0f

        };

}


mat4f mat4f_proj_perspective(float fov_rad, float aspect, float near_z, float far_z)
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


vec4f vec4f_mul_mat4f(vec4f vec, mat4f mat)
{

        return (vec4f)
        {

                .x = vec.x * mat.r00 + vec.y * mat.r10 + vec.z * mat.r20 + vec.w * mat.r30,
                .y = vec.x * mat.r01 + vec.y * mat.r11 + vec.z * mat.r21 + vec.w * mat.r31,
                .z = vec.x * mat.r02 + vec.y * mat.r12 + vec.z * mat.r22 + vec.w * mat.r32,
                .w = vec.x * mat.r03 + vec.y * mat.r13 + vec.z * mat.r23 + vec.w * mat.r33,

        };

}