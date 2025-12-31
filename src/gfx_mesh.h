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


#define VERTEX_SIZE 9
#define INDICE_SIZE 3


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


enum gfx_error  mesh_hire(struct mesh* mesh);
void            mesh_fire(struct mesh* mesh);


// this is kind of ad-hoc in my opinion, but it gets it done
// first 3 word function too
static inline bool mesh_triangle_offscreen(vec4f position1, vec4f position2, vec4f position3, int width, int height)
{

        if (position1.x < 0 && position2.x < 0 && position3.x < 0)                      return true;
        if (position1.x >= width && position2.x >= width && position3.x >= width)       return true;
        if (position1.y < 0 && position2.y < 0 && position3.y < 0)                      return true;
        if (position1.y >= height && position2.y >= height && position3.y >= height)    return true;


        return false;

}


#endif