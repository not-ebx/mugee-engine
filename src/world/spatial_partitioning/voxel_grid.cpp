//
// Created by Lucas Agullo on 19-03-24.
//

#include "voxel_grid.h"

#include "../../game/game_context.h"
#include "bgfx/bgfx.h"

#include <bx/math.h>

namespace World {
    VoxelGrid::VoxelGrid(const std::vector<Block3D *> &blocks) {
        grid = blocks;
    }

    void VoxelGrid::render() {
        auto program = Game::GameContext::get_instance()->getProgram();
        for (auto block: grid) {
            // Initialize
            float modelMat[16];
            bx::mtxIdentity(modelMat);

            // Translate cube to position
            float translate[16];
            auto cubePos = block->getGridPosition();
            bx::mtxTranslate(translate, cubePos.x, cubePos.y, cubePos.z);
            bx::mtxMul(modelMat, modelMat, translate);

            // Scale cubesa
            float scale[16];
            bx::mtxScale(scale, 1, 1, 1);
            bx::mtxMul(modelMat, modelMat, scale);

            // SEt model matrix for rendering
            bgfx::setTransform(modelMat);

            bgfx::setVertexBuffer(0, block->getVbh());
            bgfx::setIndexBuffer(block->getIbh());

            bgfx::submit(0, program);
        }
    }


}// namespace World