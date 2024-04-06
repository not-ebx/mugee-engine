//
// Created by Lucas Agullo on 23-03-24.
//

#ifndef PLAYABLE_STATE_H
#define PLAYABLE_STATE_H

#include "../../common/patterns/singleton.h"
#include "abstract/game_state.h"

namespace game {
class PlayableState : public GameState, public Singleton<PlayableState> {
 public:
  void Init(GameStateManager* ctx) override;
  void Update(GameStateManager* ctx) override;
  void End(GameStateManager* ctx) override;
};
}  // namespace game

#endif  //PLAYABLE_STATE_H
