//
// Created by Lucas Agullo on 25-03-24.
//

#include "setup_state.h"

#include "../../common/file-ops.h"
#include "../../graphics/structs/pos_tex_vertex.h"
#include "playable_state.h"

namespace game {
void SetupState::Init(GameStateManager* ctx) {
  // Initialize render context
  ctx->SetRenderContext(std::make_unique<RenderContext>());
}

void SetupState::Update(GameStateManager* ctx) {
  // Game is loaded. poggers
  ctx->PopState();
}
void SetupState::End(GameStateManager* ctx) {
  // TODO create a different state to handle "world" loading
  //ctx->SetPlayerContext(std::make_unique<PlayerContext>());
  ctx->PopState();
  ctx->PushState(&PlayableState::Instance());
}
}  // namespace game