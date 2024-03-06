//
// Created by Lucas Agullo on 02-03-24.
//

#include <bgfx/bgfx.h>

#ifndef SDL_BGFX_IMGUI_STARTER_POS_TEX_VERTEX_H
#define SDL_BGFX_IMGUI_STARTER_POS_TEX_VERTEX_H

namespace Graphics{
    struct PosTexVertex
    {
        float x, y, z; // Position
        uint32_t rgba; // Color number
        float u, v;    // Texture coordinates

        static bgfx::VertexLayout ms_layout;
        static void init();
    };

    void create_vertex(PosTexVertex* vertex, float x, float y, float z, float u, float v);
}


#endif // SDL_BGFX_IMGUI_STARTER_POS_TEX_VERTEX_H
