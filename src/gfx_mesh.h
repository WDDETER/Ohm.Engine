//
//      gfx_mesh.h  (12/29/2025)
//      by Jaidev Bormann
//


#ifndef _OHM_GFX_MESH_H
#define _OHM_GFX_MESH_H


#include <stdint.h>
#include <stdbool.h>

#include "gfx_error.h"
#include "vec4_helper.h"
#include "mat4_helper.h"


#define VERTEX_SIZE 9
#define INDICE_SIZE 3

#define VERTEX_W_MINIMUM        0.01f
#define VERTEX_W_HEALTHY(w)     (w > VERTEX_W_MINIMUM)


struct vertex
{

        vec4f position;
        vec3f normal;
        vec2f texture;

};


struct mesh
{

        struct vertex*  vertices;
        uint32_t*       indices;


        int             vertices_count, vertices_countbytes;
        int             indices_height, indices_size, indices_sizebytes;

};


enum gfx_error  mesh_hire       (struct mesh* mesh);
void            mesh_fire       (struct mesh* mesh);
void            mesh_wireframe  (struct painter* painter, struct mesh* mesh, mat4f mvp, color32i wireframe_color);


#endif