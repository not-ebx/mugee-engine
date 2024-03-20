//
// Created by Lucas Agullo on 11-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_TANGIBLE_OBJECT_H
#define SDL_BGFX_IMGUI_STARTER_TANGIBLE_OBJECT_H

#include "../../graphics/rendering/abstract/renderable_object.h"
#include "enum/block_data.h"

class Block3D : public Rendering::RenderableObject {
protected:
    BlockType blockId;
    Vector3 gridPos;

public:
    Block3D();
    Block3D(BlockType blockId);
    static Block3D *build();
    Block3D *createBlock(BlockType blockId);
    void setGridPosition(const Vector3 &position);
    Vector3 getGridPosition();
};


#endif//SDL_BGFX_IMGUI_STARTER_TANGIBLE_OBJECT_H
