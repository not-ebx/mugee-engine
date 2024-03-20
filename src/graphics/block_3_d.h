//
// Created by Lucas Agullo on 12-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_BLOCK_3_D_H
#define SDL_BGFX_IMGUI_STARTER_BLOCK_3_D_H

#include "../game/objects/block_3d.h"
#include "rendering/abstract/renderable_object.h"
namespace Graphics {
    std::vector<PosTexVertex> getBlockVertices(TextureRegion &region);
    std::vector<uint16_t> getBlockTriangles();
}// namespace Graphics
#endif//SDL_BGFX_IMGUI_STARTER_BLOCK_3_D_H
