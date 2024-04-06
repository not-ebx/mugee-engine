//
// Created by Lucas Agullo on 05-04-24.
//

#ifndef FUNNYGEMU_SRC_WORLD_SPATIAL_PARTITIONING_VOXEL_GRID_H_
#define FUNNYGEMU_SRC_WORLD_SPATIAL_PARTITIONING_VOXEL_GRID_H_

#include "../../graphics/objects/block_3_d.h"

namespace game {
class GameStateManager;
}

namespace world {

class VoxelGrid {
 private:
  //Block3D *grid[32][32][32] = {};
  std::vector<graphics::Block3D*> grid;

 public:
  explicit VoxelGrid(const std::vector<graphics::Block3D*>& blocks);
  void Render(game::GameStateManager* ctx);
};

}  // namespace world

#endif  //FUNNYGEMU_SRC_WORLD_SPATIAL_PARTITIONING_VOXEL_GRID_H_
