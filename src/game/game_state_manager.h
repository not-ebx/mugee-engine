//
// Created by Lucas Agullo on 04-04-24.
//

#ifndef FUNNYGEMU_SRC_GAME_GAME_STATE_MANAGER_H_
#define FUNNYGEMU_SRC_GAME_GAME_STATE_MANAGER_H_

#include <stack>
#include "context/player_context.h"
#include "context/render_context.h"
#include "state/abstract/game_state.h"

namespace game {
class GameState;
class GameStateManager {
 private:
  std::unique_ptr<RenderContext> r_ctx;
  std::unique_ptr<PlayerContext> p_ctx;
  std::stack<GameState*> statuses;

 public:
  PlayerContext* GetPlayerContext();
  void SetPlayerContext(std::unique_ptr<PlayerContext> new_context);
  RenderContext* GetRenderContext();
  void SetRenderContext(std::unique_ptr<RenderContext> new_context);

  void RunGame();
  void PushState(GameState* newState);
  void PopState();
  int UpdateGame();
  GameState* CurrentState();
};

}  // namespace game

#endif  //FUNNYGEMU_SRC_GAME_GAME_STATE_MANAGER_H_
