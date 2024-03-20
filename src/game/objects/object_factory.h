//
// Created by Lucas Agullo on 11-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_OBJECT_FACTORY_H
#define SDL_BGFX_IMGUI_STARTER_OBJECT_FACTORY_H


#include "../../graphics/texture.h"
#include "block_3d.h"
#include "enum/block_data.h"
namespace ObjectFactory {
    Block3D *createObject(BlockType blockType);
};


#endif//SDL_BGFX_IMGUI_STARTER_OBJECT_FACTORY_H
