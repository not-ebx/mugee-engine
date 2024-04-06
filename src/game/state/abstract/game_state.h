//
// Created by Lucas Agullo on 04-04-24.
//

#ifndef FUNNYGEMU_SRC_GAME_STATE_ABSTRACT_GAME_STATE_H_
#define FUNNYGEMU_SRC_GAME_STATE_ABSTRACT_GAME_STATE_H_

#include "../../game_state_manager.h"
namespace game {
class GameStateManager;
class GameState {
 public:
  virtual ~GameState() = default;
  virtual void Init(GameStateManager* ctx) = 0;
  virtual void Update(GameStateManager* ctx) = 0;
  virtual void End(GameStateManager* ctx) = 0;
};
};  // namespace game

#endif  //FUNNYGEMU_SRC_GAME_STATE_ABSTRACT_GAME_STATE_H_
