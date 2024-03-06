//
// Created by Lucas Agullo on 05-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_RENDER_BATCH_H
#define SDL_BGFX_IMGUI_STARTER_RENDER_BATCH_H

#include "../structs/cube.h"
#include <bgfx/bgfx.h>
#include <vector>
namespace Rendering {
    struct RenderBatch {
        bgfx::VertexBufferHandle vertexBuffer;
        bgfx::IndexBufferHandle indexBuffer;
        bgfx::TextureHandle texture;
        std::vector<Graphics::Cube*> cubes;
        uint64_t renderState;
    };
}

#endif // SDL_BGFX_IMGUI_STARTER_RENDER_BATCH_H
