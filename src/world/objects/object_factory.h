//
// Created by Lucas Agullo on 05-04-24.
//

#ifndef FUNNYGEMU_SRC_WORLD_OBJECTS_OBJECT_FACTORY_H_
#define FUNNYGEMU_SRC_WORLD_OBJECTS_OBJECT_FACTORY_H_

#include "../../game/game_state_manager.h"
#include "../../graphics/enum/block_data.h"
#include "../../graphics/objects/block_3_d.h"
namespace world {
graphics::Block3D* CreateObject(game::GameStateManager* ctx,
                                BlockType blockType);
graphics::Block3D* CreateObject(game::GameStateManager* ctx,
                                BlockType blockType, bx::Vec3 pos);
}  // namespace world

#endif  //FUNNYGEMU_SRC_WORLD_OBJECTS_OBJECT_FACTORY_H_
