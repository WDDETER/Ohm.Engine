//
//      gfx_mesh.c  (12/29/2025)
//      by Jaidev Bormann
//


#include <stdlib.h>
#include <stdio.h>

#include "proj_helper.h"
#include "gfx_mesh.h"


enum gfx_error mesh_hire(struct mesh* mesh)
{

        if (!mesh)
                return MESH_NULL_POINTER;

        mesh->vertices_countbytes = mesh->vertices_count * sizeof(struct vertex);

        mesh->indices_size      = INDICE_SIZE * mesh->indices_height;
        mesh->indices_sizebytes = mesh->indices_size * sizeof(uint32_t);

        mesh->vertices  = (struct vertex*)malloc(mesh->vertices_countbytes);
        mesh->indices   = (uint32_t*)malloc(mesh->indices_sizebytes);


        if (!mesh->vertices)
                return MESH_VERTICES_FAILED_ALLOCATION;
        
        if (!mesh->indices)
                return MESH_INDICES_FAILED_ALLOCATION;


        return MESH_HEALTHY;

}


void mesh_fire(struct mesh* mesh)
{

        free(mesh->vertices);
        free(mesh->indices);

        mesh->vertices  = NULL;
        mesh->indices   = NULL;

}


void mesh_wireframe(struct painter* painter, struct mesh* mesh, mat4f mvp, color32i wireframe_color)
{

        for (int i = 0; i < mesh->indices_size; i += 3)
        {

                struct vertex vertex1 = mesh->vertices[mesh->indices[i]];
                struct vertex vertex2 = mesh->vertices[mesh->indices[i + 1]];
                struct vertex vertex3 = mesh->vertices[mesh->indices[i + 2]];

                vertex1.position = vec4f_mul_mat4f(vertex1.position, mvp);
                vertex2.position = vec4f_mul_mat4f(vertex2.position, mvp);
                vertex3.position = vec4f_mul_mat4f(vertex3.position, mvp);

                bool vertex1_healthy = VERTEX_W_HEALTHY(vertex1.position.w);
                bool vertex2_healthy = VERTEX_W_HEALTHY(vertex2.position.w);
                bool vertex3_healthy = VERTEX_W_HEALTHY(vertex3.position.w);

                if (!vertex1_healthy || !vertex2_healthy || !vertex3_healthy)
                        continue;

                vertex1.position = vec4f_div_scalar(vertex1.position, vertex1.position.w);
                vertex2.position = vec4f_div_scalar(vertex2.position, vertex2.position.w);
                vertex3.position = vec4f_div_scalar(vertex3.position, vertex3.position.w);

                vertex1.position = projection_screenspace(vertex1.position, painter->pixels_width, painter->pixels_height);
                vertex2.position = projection_screenspace(vertex2.position, painter->pixels_width, painter->pixels_height);
                vertex3.position = projection_screenspace(vertex3.position, painter->pixels_width, painter->pixels_height);

                painter_line(painter, vertex1.position.x, vertex1.position.y, vertex2.position.x, vertex2.position.y, wireframe_color);
                painter_line(painter, vertex1.position.x, vertex1.position.y, vertex3.position.x, vertex3.position.y, wireframe_color);
                painter_line(painter, vertex2.position.x, vertex2.position.y, vertex3.position.x, vertex3.position.y, wireframe_color);

        }       

}