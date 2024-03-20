//
// Created by Lucas Agullo on 19-03-24.
//

#ifndef VOXEL_GRID_H
#define VOXEL_GRID_H
#include "../../game/objects/block_3d.h"

namespace World {

    class VoxelGrid {
    private:
        //Block3D *grid[32][32][32] = {};
        std::vector<Block3D *> grid;

    public:
        explicit VoxelGrid(const std::vector<Block3D *> &blocks);
        void render();
    };

}// namespace World

#endif//VOXEL_GRID_H
