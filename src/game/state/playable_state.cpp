//
// Created by Lucas Agullo on 23-03-24.
//

#include "playable_state.h"
#include "../../../bgfx-imgui/imgui_impl_bgfx.h"
#include "../../../sdl-imgui/imgui_impl_sdl2.h"
#include "../../world/objects/object_factory.h"

namespace game {
void PlayableState::Init(GameStateManager* ctx) {
  auto playerCtx = std::make_unique<PlayerContext>();

  std::vector<graphics::Block3D*> blocks;
  for (float i = 0; i < 10; i++) {
    for (float j = 0; j < 10; j++) {
      auto newcube = world::CreateObject(ctx, BlockType::DIRT);
      newcube->SetGridPosition({j * 2, 0, i * 2});
      blocks.push_back(newcube);
    }
  }
  // For testing, let's just create a simple voxel grid.
  playerCtx->SetGrid(std::make_unique<world::VoxelGrid>(blocks));

  ctx->SetPlayerContext(std::move(playerCtx));
}
void PlayableState::Update(GameStateManager* ctx) {
  // Imgui Stuff
  ImGui_Implbgfx_NewFrame();
  ImGui_ImplSDL2_NewFrame();

  ImGui::NewFrame();
  ImGui::ShowDemoWindow();  // your drawing here
  ImGui::Render();
  ImGui_Implbgfx_RenderDrawLists(ImGui::GetDrawData());

  ctx->GetPlayerContext()->GetPlayer()->Update();
  ctx->GetRenderContext()->GetTexture(0)->bindTexture();
  ctx->GetPlayerContext()->GetGrid()->Render(ctx);

  ctx->GetRenderContext()->ProgramSubmit(0);
  bgfx::frame();
}
void PlayableState::End(GameStateManager* ctx) {}
}  // namespace game
