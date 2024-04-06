//
// Created by Lucas Agullo on 25-03-24.
//

#ifndef SETUP_STATE_H
#define SETUP_STATE_H
#include "../../common/patterns/singleton.h"
#include "abstract/game_state.h"

namespace game {

class SetupState : public GameState, public Singleton<SetupState> {
 public:
  void Init(GameStateManager* ctx) override;
  void Update(GameStateManager* ctx) override;
  void End(GameStateManager* ctx) override;
};

}  // namespace game

#endif  //SETUP_STATE_H
