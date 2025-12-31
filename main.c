//
//      main.c  (12/28/2025)
//      by Jaidev Bormann
//


//      Example file for testing.


#include "win_main.h"
#include "gfx_main.h"
#include "gfx_mesh.h"

#include "proj_helper.h"
#include "cam_helper.h"
#include "tran_helper.h"
#include "mat4_helper.h"
#include "vec4_helper.h"
#include "math_helper.h"

#include <stdio.h>


int main(void)
{

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
        mesh.vertices_count = 4;
        mesh.indices_height = 2;

        mesh_hire(&mesh);

        mesh.vertices[0].position.x = -1.0f; mesh.vertices[0].position.y = -1.0f; mesh.vertices[0].position.w = 1.0f;
        mesh.vertices[1].position.x = -1.0f; mesh.vertices[1].position.y = 1.0f; mesh.vertices[1].position.w = 1.0f;
        mesh.vertices[2].position.x = 1.0f; mesh.vertices[2].position.y = -1.0f; mesh.vertices[2].position.w = 1.0f;
        mesh.vertices[3].position.x = 1.0f; mesh.vertices[3].position.y = 1.0f; mesh.vertices[3].position.w = 1.0f;

        mesh.indices[0] = 0; mesh.indices[1] = 1; mesh.indices[2] = 2;
        mesh.indices[3] = 1; mesh.indices[4] = 2; mesh.indices[5] = 3;


        color32i clear_color    = { 0 };
        color32i line_color     = { 0 };
        line_color.a = 0xFF;
        line_color.r = 0xFF;
        line_color.g = 0xFF;
        line_color.b = 0xFF;


        struct projf projf      = { 0 };
        projf.fov_rad           = RADF_TO_DEGF(70.0f);
        projf.aspect            = 320.0f / 240.0f;
        projf.near_z            = 1.0f;
        projf.far_z             = 1000.0f;

        struct camf camf        = { 0 };
        camf.eye.x              = 0.0f; camf.eye.y            = 0.0f; camf.eye.z            = 0.0f;
        camf.target.x           = 0.0f; camf.target.y         = 0.0f; camf.target.z         = -5.0f;
        camf.up.x               = 0.0f; camf.up.y             = 1.0f; camf.up.z             = 0.0f;

        struct tranf tranf      = { 0 };
        tranf.translate         = mat4f_translate(0.0f, 0.0f, -5.0f);
        tranf.scale             = mat4f_scale(1.0f, 1.0f, 1.0f);

        vec3f angles = { 0 };


        while (window.is_running)
        {

                window_pump(&window, 0, 0);

                angles.x += 0.0001f;
                angles.y += 0.0001f;
                angles.z += 0.0001f;

                tranf.rotate_x = mat4f_rotate_x(angles.x);
                tranf.rotate_y = mat4f_rotate_y(angles.y);
                tranf.rotate_z = mat4f_rotate_z(angles.z);

                tranf.rotation  = MAT4_MULITPLY_ORDER(tranf.rotate_x, tranf.rotate_y, tranf.rotate_z);
                tranf.transform = MAT4_MULITPLY_ORDER(tranf.scale, tranf.rotation, tranf.translate);

                camf.view               = mat4f_cam_lookat      (camf.forward, camf.right, camf.up, camf.eye, camf.target);
                projf.perspective       = mat4f_proj_perspective(projf.fov_rad, projf.aspect, projf.near_z, projf.far_z);

                mat4f mvp = MAT4_MULITPLY_ORDER(tranf.transform, camf.view, projf.perspective)


                for (int i = 0; i < mesh.indices_size; i += 3)
                {

                        struct vertex v0 = mesh.vertices[mesh.indices[i]];
                        struct vertex v1 = mesh.vertices[mesh.indices[i + 1]];
                        struct vertex v2 = mesh.vertices[mesh.indices[i + 2]];

                        v0.position = vec4f_mul_mat4f(v0.position, mvp);
                        v1.position = vec4f_mul_mat4f(v1.position, mvp);
                        v2.position = vec4f_mul_mat4f(v2.position, mvp);

                        v0.position = vec4f_div_scalar(v0.position, v0.position.w);
                        v1.position = vec4f_div_scalar(v1.position, v1.position.w);
                        v2.position = vec4f_div_scalar(v2.position, v2.position.w);

                        v0.position = projection_screenspace(v0.position, painter.pixels_width, painter.pixels_height);
                        v1.position = projection_screenspace(v1.position, painter.pixels_width, painter.pixels_height);
                        v2.position = projection_screenspace(v2.position, painter.pixels_width, painter.pixels_height);

                        bool offscreen = mesh_triangle_offscreen(v0.position, v1.position, v2.position, painter.pixels_width, painter.pixels_height);

                        if (offscreen)
                                continue;

                        painter_line(&painter, v0.position.x, v0.position.y, v1.position.x, v1.position.y, line_color);
                        painter_line(&painter, v0.position.x, v0.position.y, v2.position.x, v2.position.y, line_color);
                        painter_line(&painter, v1.position.x, v1.position.y, v2.position.x, v2.position.y, line_color);

                }


                painter_present(&painter, &window, clear_color);

        }


        mesh_fire       (&mesh);
        painter_fire    (&painter);
        window_fire     (&window);


        return 0;

}