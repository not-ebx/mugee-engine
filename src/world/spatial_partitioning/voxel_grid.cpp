//
// Created by Lucas Agullo on 05-04-24.
//

#include "voxel_grid.h"
#include "../../game/game_state_manager.h"
#include "bgfx/bgfx.h"

#include <bx/math.h>

namespace world {
VoxelGrid::VoxelGrid(const std::vector<graphics::Block3D*>& blocks) {
  grid = blocks;
}

void VoxelGrid::Render(game::GameStateManager* ctx) {
  //auto program = Game::GameContext::get_instance()->getProgram();
  for (auto block : grid) {
    // Initialize
    float modelMat[16];
    bx::mtxIdentity(modelMat);

    // Translate cube to position
    float translate[16];
    auto cubePos = block->GetGridPosition();
    bx::mtxTranslate(translate, cubePos.x, cubePos.y, cubePos.z);
    bx::mtxMul(modelMat, modelMat, translate);

    // Scale cubesa
    float scale[16];
    bx::mtxScale(scale, 1, 1, 1);
    bx::mtxMul(modelMat, modelMat, scale);

    // SEt model matrix for rendering
    bgfx::setTransform(modelMat);

    bgfx::setVertexBuffer(0, block->GetVbh());
    bgfx::setIndexBuffer(block->GetIbh());

    //ctx->GetRenderContext()->ProgramSubmit(0);
    //bgfx::submit(0, program);
  }
}

}  // namespace world