#include <bgfx/bgfx.h>

#include <SDL.h>

#include "../bgfx-imgui/imgui_impl_bgfx.h"
#include "../sdl-imgui/imgui_impl_sdl2.h"
#include "game/game_context.h"
#include "game/objects/object_factory.h"
#include "world/spatial_partitioning/voxel_grid.h"


void main_loop() {
    auto context = Game::GameContext::get_instance();

    for (SDL_Event current_event; SDL_PollEvent(&current_event) != 0;) {
        ImGui_ImplSDL2_ProcessEvent(&current_event);
        if (current_event.type == SDL_QUIT) {
            context->setQuit(true);
            break;
        }
    }

    ImGui_Implbgfx_NewFrame();
    ImGui_ImplSDL2_NewFrame();

    ImGui::NewFrame();
    ImGui::ShowDemoWindow();// your drawing here
    ImGui::Render();
    ImGui_Implbgfx_RenderDrawLists(ImGui::GetDrawData());


    context->getPlayer()->update();

    auto voxelGrid = new World::VoxelGrid(context->cubeQueue);
    context->getLoadedTexture(0)->bindTexture();
    voxelGrid->render();
    bgfx::frame();
}

int main(int argc, char **argv) {
    Game::GameContext *game = Game::GameContext::get_instance();
    // Create a very simple flat ground for testing.
    for (float i = 0; i < 10; i++) {
        for (float j = 0; j < 10; j++) {
            auto newcube = ObjectFactory::createObject(BlockType::DIRT);
            newcube->setPosition({j * 2, 0, i * 2});
            game->cubeQueue.push_back(newcube);
        }
    }

    // Load game textures
    while (!game->isQuit()) {
        main_loop();
    }

    delete game;

    return 0;
}
