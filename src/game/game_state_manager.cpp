//
// Created by Lucas Agullo on 04-04-24.
//

#include "game_state_manager.h"
#include "../../sdl-imgui/imgui_impl_sdl2.h"
#include "state/setup_state.h"

namespace game {
void GameStateManager::RunGame() {
  auto ptr = &SetupState::Instance();
  PushState(ptr);
}

void GameStateManager::PushState(GameState* newState) {
  statuses.push(newState);
  CurrentState()->Init(this);
}

int GameStateManager::UpdateGame() {
  bool quit = false;

  while (!quit) {
    SDL_Event event;
    for (SDL_Event current_event; SDL_PollEvent(&current_event) != 0;) {
      ImGui_ImplSDL2_ProcessEvent(&current_event);
      if (current_event.type == SDL_QUIT) {
        quit = true;
        break;
      }
    }

    GameState* state = CurrentState();
    if (!state) {
      printf("Game has no state loaded. What the fuck?");
      break;
    }
    state->Update(this);
  }
  /*
  if (CurrentState()) {
    CurrentState()->End(this);
  }
   */
}

void GameStateManager::PopState() {
  if (CurrentState()) {
    auto current_state = CurrentState();
    statuses.pop();
    current_state->End(this);
  }
}
GameState* GameStateManager::CurrentState() {
  return statuses.size() > 0 ? statuses.top() : nullptr;
}

PlayerContext* GameStateManager::GetPlayerContext() {
  return p_ctx.get();
}

RenderContext* GameStateManager::GetRenderContext() {
  return r_ctx.get();
}

void GameStateManager::SetRenderContext(
    std::unique_ptr<RenderContext> new_context) {
  this->r_ctx = std::move(new_context);
}

void GameStateManager::SetPlayerContext(
    std::unique_ptr<PlayerContext> new_context) {
  this->p_ctx = std::move(new_context);
}

}  // namespace game