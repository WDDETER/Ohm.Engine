//
//      main.c  (12/28/2025)
//      by Jaidev Bormann
//


//      Example file for testing.
//      Do NOT expect super clean structure, this is only for testing tech.


#include "win_main.h"
#include "gfx_main.h"
#include "gfx_mesh.h"

#include "win_input.h"
#include "win_time.h"

#include "proj_helper.h"
#include "cam_helper.h"
#include "tran_helper.h"
#include "mat4_helper.h"
#include "vec4_helper.h"
#include "math_helper.h"

#include <stdio.h>


int main(void)
{

        struct clock clock = clock_hire();

        struct window window    = { 0 };

        window.style            = (WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE);

        window.class_name       = WINDOW_DEF_CLASS_NAME;
        window.name             = WINDOW_DEF_NAME;

        window.width            = WINDOW_DEF_WIDTH;
        window.height           = WINDOW_DEF_HEIGHT;

        window.procedure        = window_procedure;

        window_center   (&window);
        window_hire     (&window);
        

        struct painter painter  = { 0 };

        painter.pixels_width    = 320;
        painter.pixels_height   = 240;

        painter.bit_compression = PAINTER_DEF_BIT_COMPRESSION;
        painter.bit_count       = PAINTER_DEF_BIT_COUNT;
        painter.bit_planes      = PAINTER_DEF_BIT_PLANES;

        painter_hire(&painter);


        struct mesh mesh = { 0 };
        mesh_hire_obj(&mesh, "../Sphere.obj");


        color32i clear_color    = { 0 };
        color32i line_color     = { 0 };
        line_color.a = 0xFF;
        line_color.r = 0x00;
        line_color.g = 0x00;
        line_color.b = 0xFF;


        struct projection proj          = { 0 };
        proj.fov_rad                    = DEG_TO_RAD(90.0f);
        proj.aspect                     = 320.0f / 240.0f;
        proj.near_z                     = 0.5f;
        proj.far_z                      = 1000.0f;

        struct camera cam               = { 0 };
        cam.eye.x                       = 0.0f; cam.eye.y            = 1.5f; cam.eye.z            = -10.0f;
        cam.target.x                    = 0.0f; cam.target.y         = 0.0f; cam.target.z         = 5.0f;
        cam.up.x                        = 0.0f; cam.up.y             = 1.0f; cam.up.z             = 0.0f;


        vec3f angles = { 0 };

        struct transform tran           = { 0 };
        tran.translate                  = transform_translate           (0.0f, 0.0f, 3.0f);
        tran.scale                      = transform_scale               (8.0f, 8.0f, 8.0f);
        tran.rotate_x                   = transform_rotate_x            (angles.x);
        tran.rotate_y                   = transform_rotate_y            (angles.y);
        tran.rotate_z                   = transform_rotate_z            (angles.z);
        tran.rotation                   = MAT4_MULTIPLY_ORDER           (tran.rotate_x, tran.rotate_y, tran.rotate_z);


        while (window.is_running)
        {

                window_pump     (&window, 0, 0);
                clock_tick      (&clock);

                printf("%f\n", clock.delta_time);


                vec3f move_dir          = { 0 };

                vec3f forward_dir_xz    = { .x = cam.forward.x, .y = 0.0f, .z = cam.forward.z };
                vec3f right_dir_xz      = { .x = cam.right.x, .y = 0.0f, .z = cam.right.z };

                if (window_key_held('W')) move_dir = vec3f_add(move_dir, forward_dir_xz);
                if (window_key_held('S')) move_dir = vec3f_sub(move_dir, forward_dir_xz);
                if (window_key_held('A')) move_dir = vec3f_sub(move_dir, right_dir_xz);
                if (window_key_held('D')) move_dir = vec3f_add(move_dir, right_dir_xz);

                if (window_key_held('E')) cam.eye.y += 5.0f * clock.delta_time;
                if (window_key_held('Q')) cam.eye.y -= 5.0f * clock.delta_time;

                if (vec3f_length_squared(move_dir) > 0.0f)
                        move_dir = vec3f_unit(move_dir);

                cam.eye        = vec3f_add(cam.eye, vec3f_mul_scalar(move_dir, 6.0f * clock.delta_time));
                cam.target     = vec3f_add(cam.target, vec3f_mul_scalar(move_dir, 6.0f * clock.delta_time));


                vec3f up_new = camera_angles(&cam.forward, &cam.right, cam.up, cam.angles);

                if (window_key_held(VK_LEFT))   cam.angles.x -= 3.0f * clock.delta_time;
                if (window_key_held(VK_RIGHT))  cam.angles.x += 3.0f * clock.delta_time;

                cam.target = vec3f_add(cam.eye, cam.forward);


                cam.view                = camera_lookat         (&cam.forward, &cam.right, up_new, cam.eye, cam.target);
                proj.perspective        = projection_perspective(proj.fov_rad, proj.aspect, proj.near_z, proj.far_z);


                tran.transform          = MAT4_MULTIPLY_ORDER           (tran.scale, tran.rotation, tran.translate);
                mat4f mvp               = MAT4_MULTIPLY_ORDER           (tran.transform, cam.view, proj.perspective);

                mesh_wireframe(&painter, &mesh, mvp, line_color);


                painter_present(&painter, &window, clear_color);

        }


        mesh_fire       (&mesh);
        painter_fire    (&painter);
        window_fire     (&window);


        return 0;

}