#include <bgfx/bgfx.h>

#include <SDL.h>

#include "../bgfx-imgui/imgui_impl_bgfx.h"
#include "../sdl-imgui/imgui_impl_sdl2.h"
#include "game/game_state_manager.h"

void main_loop() {
  for (SDL_Event current_event; SDL_PollEvent(&current_event) != 0;) {
    ImGui_ImplSDL2_ProcessEvent(&current_event);
    if (current_event.type == SDL_QUIT) {
      break;
    }
  }

  ImGui_Implbgfx_NewFrame();
  ImGui_ImplSDL2_NewFrame();

  ImGui::NewFrame();
  ImGui::ShowDemoWindow();  // your drawing here
  ImGui::Render();
  ImGui_Implbgfx_RenderDrawLists(ImGui::GetDrawData());

  bgfx::frame();
}

int main(int argc, char** argv) {
  auto manager = new game::GameStateManager();
  manager->RunGame();
  manager->UpdateGame();

  return 0;
}
