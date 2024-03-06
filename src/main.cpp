#include <bgfx/bgfx.h>

#include <SDL.h>
#include <SDL_syswm.h>

#include "../bgfx-imgui/imgui_impl_bgfx.h"
#include "../imgui.h"
#include "../sdl-imgui/imgui_impl_sdl2.h"
#include "game/game_context.h"
#include "graphics/rendering/shaders.h"
#include "graphics/structs/cube.h"
#include "graphics/texture.h"


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

    float i = 0;
    for (Graphics::Cube *cube: context->cubeQueue) {
        bgfx::setVertexBuffer(0, cube->getVbh());
        bgfx::setIndexBuffer(cube->getIbh());

        cube->render();
        cube->setPosition({i * 2, 0, 0});

        bgfx::submit(0, context->getProgram());
        i++;
    }

    bgfx::frame();
}

int main(int argc, char **argv) {
    Game::GameContext *game = Game::GameContext::get_instance();

    game->cubeQueue = {
            new Graphics::Cube(new Texture("./assets/texture_test.png")),
            new Graphics::Cube(new Texture("./assets/texture_test.png")),
            new Graphics::Cube(new Texture("./assets/texture_test.png")),
            new Graphics::Cube(new Texture("./assets/texture_test.png")),
    };

    while (!game->isQuit()) {
        main_loop();
    }

    delete game;

    return 0;
}
