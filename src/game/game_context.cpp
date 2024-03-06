//
// Created by Lucas Agullo on 06-03-24.
//

#include "game_context.h"
#include "../../bgfx-imgui/imgui_impl_bgfx.h"
#include "../../file-ops.h"
#include "../../sdl-imgui/imgui_impl_sdl2.h"
#include "../graphics/rendering/shaders.h"
#include "../graphics/structs/pos_tex_vertex.h"
#include <SDL_syswm.h>
#include <string>

namespace Game {
    GameContext *GameContext::instance;

    GameContext::GameContext() {
        // Create the player :)
        player = new Player();

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
            return;
        }

        width = 1280;
        height = 720;
        window = SDL_CreateWindow(
                "Geemu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,
                height, SDL_WINDOW_SHOWN);

        if (window == nullptr) {
            printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
            return;
        }

        Graphics::PosTexVertex::init();

        SDL_SysWMinfo wmi;
        SDL_VERSION(&wmi.version);
        if (!SDL_GetWindowWMInfo(window, &wmi)) {
            printf(
                    "SDL_SysWMinfo could not be retrieved. SDL_Error: %s\n",
                    SDL_GetError());
            return;
        }
        bgfx::renderFrame();// single threaded mode

        bgfx::PlatformData pd{};
#if BX_PLATFORM_WINDOWS
        pd.nwh = wmi.info.win.window;
#elif BX_PLATFORM_OSX
        pd.nwh = wmi.info.cocoa.window;
#elif BX_PLATFORM_LINUX
        pd.ndt = wmi.info.x11.display;
        pd.nwh = (void *) (uintptr_t) wmi.info.x11.window;
#endif// BX_PLATFORM_WINDOWS ? BX_PLATFORM_OSX ? BX_PLATFORM_LINUX ? \
        // BX_PLATFORM_EMSCRIPTEN

        bgfx::Init bgfx_init;
        bgfx_init.type = bgfx::RendererType::Count;// auto choose renderer
        bgfx_init.resolution.width = width;
        bgfx_init.resolution.height = height;
        bgfx_init.resolution.reset = BGFX_RESET_VSYNC;
        bgfx_init.platformData = pd;
        bgfx::init(bgfx_init);

        bgfx::setViewClear(
                0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x6495EDFF, 1.0f, 0);
        bgfx::setViewRect(0, 0, 0, width, height);

        ImGui::CreateContext();


        ImGui_Implbgfx_Init(255);
        // TODO: Fix this macro!!
#if BX_PLATFORM_WINDOWS
        ImGui_ImplSDL2_InitForD3D(window);
#elif BX_PLATFORM_OSX
        ImGui_ImplSDL2_InitForMetal(window);
#elif BX_PLATFORM_LINUX
        ImGui_ImplSDL2_InitForOpenGL(window, nullptr);
#endif// BX_PLATFORM_WINDOWS ? BX_PLATFORM_OSX ? BX_PLATFORM_LINUX
        const std::string shader_root = "shader/build/";

        std::string vshader;
        if (!fileops::read_file(shader_root + "v_simple.bin", vshader)) {
            printf("Could not find shader vertex shader (ensure shaders have been "
                   "compiled).\n"
                   "Run compile-shaders-<platform>.sh/bat\n");
            return;
        }

        std::string fshader;
        if (!fileops::read_file(shader_root + "f_simple.bin", fshader)) {
            printf("Could not find shader fragment shader (ensure shaders have "
                   "been compiled).\n"
                   "Run compile-shaders-<platform>.sh/bat\n");
            return;
        }

        vsh = Rendering::create_shader(vshader, "vshader");
        fsh = Rendering::create_shader(fshader, "fshader");
        program = bgfx::createProgram(vsh, fsh, true);
    }
    GameContext *GameContext::get_instance() {
        if (GameContext::instance == nullptr) {
            GameContext::instance = new GameContext();
        }
        return GameContext::instance;
    }
    GameContext::~GameContext() {

        bgfx::destroy(program);

        ImGui_ImplSDL2_Shutdown();
        ImGui_Implbgfx_Shutdown();

        ImGui::DestroyContext();
        bgfx::shutdown();

        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    SDL_Window *GameContext::getWindow() const {
        return window;
    }
    void GameContext::setWindow(SDL_Window *window) {
        GameContext::window = window;
    }
    const bgfx::ProgramHandle &GameContext::getProgram() const {
        return program;
    }
    void GameContext::setProgram(const bgfx::ProgramHandle &program) {
        GameContext::program = program;
    }
    const bgfx::ShaderHandle &GameContext::getVsh() const {
        return vsh;
    }
    void GameContext::setVsh(const bgfx::ShaderHandle &vsh) {
        GameContext::vsh = vsh;
    }
    const bgfx::ShaderHandle &GameContext::getFsh() const {
        return fsh;
    }
    void GameContext::setFsh(const bgfx::ShaderHandle &fsh) {
        GameContext::fsh = fsh;
    }
    int GameContext::getWidth() const {
        return width;
    }
    void GameContext::setWidth(int width) {
        GameContext::width = width;
    }
    int GameContext::getHeight() const {
        return height;
    }
    void GameContext::setHeight(int height) {
        GameContext::height = height;
    }
    bool GameContext::isQuit() const {
        return quit;
    }
    void GameContext::setQuit(bool quit) {
        GameContext::quit = quit;
    }
    Camera *GameContext::getCamera() {
        return player->getCamera();
    }
    Player *GameContext::getPlayer() {
        return player;
    };

}// namespace Game