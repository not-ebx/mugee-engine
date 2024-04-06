//
// Created by Lucas Agullo on 04-04-24.
//

#ifndef FUNNYGEMU_SRC_GAME_CONTEXT_PLAYER_CONTEXT_H_
#define FUNNYGEMU_SRC_GAME_CONTEXT_PLAYER_CONTEXT_H_

#include "../../world/player.h"
#include "../../world/spatial_partitioning/voxel_grid.h"

namespace game {

class PlayerContext {
 private:
  std::unique_ptr<world::Player> player;
  std::unique_ptr<world::VoxelGrid> voxel_grid;

 public:
  PlayerContext();
  world::Player* GetPlayer();
  world::VoxelGrid* GetGrid();
  void SetGrid(std::unique_ptr<world::VoxelGrid> voxel_grid);
};

}  // namespace game

#endif  //FUNNYGEMU_SRC_GAME_CONTEXT_PLAYER_CONTEXT_H_
