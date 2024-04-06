//
// Created by Lucas Agullo on 04-04-24.
//

#include "player_context.h"

namespace game {

PlayerContext::PlayerContext() {
  player = std::make_unique<world::Player>();
}

world::Player* PlayerContext::GetPlayer() {
  return player.get();
}

world::VoxelGrid* PlayerContext::GetGrid() {
  return voxel_grid.get();
}

void PlayerContext::SetGrid(std::unique_ptr<world::VoxelGrid> voxel_grid) {
  this->voxel_grid = std::move(voxel_grid);
}

}  // namespace game