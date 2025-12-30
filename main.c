//
//      main.c  (12/28/2025)
//      by Jaidev Bormann
//


#include "win_main.h"
#include "gfx_main.h"
#include "gfx_mesh.h"

#include "proj_main.h"
#include "cam_main.h"

#include "mat4_helper.h"
#include "vec4_helper.h"

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


        color32 color = { 0 };

        float x_angle = 0.0f;
        float y_angle = 0.0f;
        float z_angle = 0.0f;

        mat4f translate = mat4_translate(0.0f, 0.0f, 5.0f);
        mat4f scale     = mat4_scale(1.0f, 1.0f, 1.0f);


        struct projection proj  = { 0 };
        proj.fov_radians        = 70.0f * (3.14159f / 180.0f);
        proj.aspect             = 320.0f / 240.0f;
        proj.near_z             = 1.0f;
        proj.far_z              = 1000.0f;

        struct camera camera    = { 0 };
        camera.eye.x            = 0.0f;
        camera.eye.y            = 0.0f;
        camera.eye.z            = 0.0f;

        camera.target.x         = 0.0f;
        camera.target.y         = 0.0f;
        camera.target.z         = 5.0f;

        camera.up.x             = 0.0f;
        camera.up.y             = 1.0f; 
        camera.up.z             = 0.0f;


        while (window.is_running)
        {

                window_pump(&window, 0, 0);

                x_angle += 0.0001f;
                y_angle += 0.0001f;
                z_angle += 0.0001f;

                mat4f rotate_x = mat4_rotate_x(x_angle);
                mat4f rotate_y = mat4_rotate_y(y_angle);
                mat4f rotate_z = mat4_rotate_z(z_angle);

                mat4f rotation  = mat4_mul_mat4(rotate_z, mat4_mul_mat4(rotate_y, rotate_x));
                mat4f transform = mat4_mul_mat4(scale, mat4_mul_mat4(rotation, translate));

                camera_lookat           (&camera);
                projection_perspective  (&proj);

                mat4f mvp = mat4_mul_mat4(transform, mat4_mul_mat4(camera.view, proj.projection));


                for (int i = 0; i < mesh.indices_size; i += 3)
                {

                        struct vertex v0 = mesh.vertices[mesh.indices[i]];
                        struct vertex v1 = mesh.vertices[mesh.indices[i + 1]];
                        struct vertex v2 = mesh.vertices[mesh.indices[i + 2]];


                        v0.position = vec4_mul_mat4(v0.position, mvp);
                        v1.position = vec4_mul_mat4(v1.position, mvp);
                        v2.position = vec4_mul_mat4(v2.position, mvp);

                        v0.position = vec4_div_scalar(v0.position, v0.position.w);
                        v1.position = vec4_div_scalar(v1.position, v1.position.w);
                        v2.position = vec4_div_scalar(v2.position, v2.position.w);

                        v0.position = projection_screenspace(v0.position, painter.pixels_width, painter.pixels_height);
                        v1.position = projection_screenspace(v1.position, painter.pixels_width, painter.pixels_height);
                        v2.position = projection_screenspace(v2.position, painter.pixels_width, painter.pixels_height);


                        painter.pixels[(pixel)v0.position.y * painter.pixels_width + (pixel)v0.position.x] = 0xFFFF0000;
                        painter.pixels[(pixel)v1.position.y * painter.pixels_width + (pixel)v1.position.x] = 0xFF00FF00;
                        painter.pixels[(pixel)v2.position.y * painter.pixels_width + (pixel)v2.position.x] = 0xFF0000FF;

                }


                painter_present(&painter, &window, color);

        }


        mesh_fire       (&mesh);
        painter_fire    (&painter);
        window_fire     (&window);


        return 0;

}