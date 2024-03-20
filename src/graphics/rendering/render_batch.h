//
// Created by Lucas Agullo on 05-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_RENDER_BATCH_H
#define SDL_BGFX_IMGUI_STARTER_RENDER_BATCH_H

#include "abstract/renderable.h"
#include <bgfx/bgfx.h>
#include <vector>

namespace Rendering {
    struct RenderBatch {
        bgfx::VertexBufferHandle vertexBuffer;
        bgfx::IndexBufferHandle indexBuffer;
        bgfx::TextureHandle texture;
        std::vector<Renderable> renderableQueue;
        uint64_t renderState;
    };
}// namespace Rendering

#endif// SDL_BGFX_IMGUI_STARTER_RENDER_BATCH_H
