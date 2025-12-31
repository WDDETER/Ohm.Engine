//
//      gfx_mesh.c  (12/29/2025)
//      by Jaidev Bormann
//


#include <stdlib.h>

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