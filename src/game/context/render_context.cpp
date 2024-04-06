//
// Created by Lucas Agullo on 04-04-24.
//

#include "render_context.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/math.h>

#include <SDL.h>
#include <SDL_syswm.h>
#include "../../../bgfx-imgui/imgui_impl_bgfx.h"
#include "../../../sdl-imgui/imgui_impl_sdl2.h"
#include "../../common/file-ops.h"
#include "../../graphics/structs/pos_tex_vertex.h"

namespace game {

bgfx::ShaderHandle RenderContext::CreateShader(const std::string& shader,
                                               const char* name) {
  const bgfx::Memory* mem = bgfx::copy(shader.data(), shader.size());
  const bgfx::ShaderHandle handle = bgfx::createShader(mem);
  bgfx::setName(handle, name);
  return handle;
}

RenderContext::RenderContext() {

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
    return;
  }

  uint width = 1280;
  uint height = 720;

  auto window = SDL_CreateWindow("Geemu", SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED, width, height,
                                 SDL_WINDOW_SHOWN);

  if (window == nullptr) {
    printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
    return;
  }

  graphics::PosTexVertex::init();

  SDL_SysWMinfo wmi;
  SDL_VERSION(&wmi.version);
  if (!SDL_GetWindowWMInfo(window, &wmi)) {
    printf("SDL_SysWMinfo could not be retrieved. SDL_Error: %s\n",
           SDL_GetError());
    return;
  }
  bgfx::renderFrame();
  bgfx::PlatformData pd{};
#if BX_PLATFORM_WINDOWS
  pd.nwh = wmi.info.win.window;
#elif BX_PLATFORM_OSX
  pd.nwh = wmi.info.cocoa.window;
#elif BX_PLATFORM_LINUX
  pd.ndt = wmi.info.x11.display;
  pd.nwh = (void*)(uintptr_t)wmi.info.x11.window;
#endif  // BX_PLATFORM_WINDOWS ? BX_PLATFORM_OSX ? BX_PLATFORM_LINUX ? \
        // BX_PLATFORM_EMSCRIPTEN

  bgfx::Init bgfx_init;
  bgfx_init.type = bgfx::RendererType::Count;  // auto choose renderer
  bgfx_init.resolution.width = width;
  bgfx_init.resolution.height = height;
  bgfx_init.resolution.reset = BGFX_RESET_VSYNC;
  bgfx_init.platformData = pd;
  bgfx::init(bgfx_init);

  bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x6495EDFF, 1.0f,
                     0);
  bgfx::setViewRect(0, 0, 0, width, height);

  ImGui::CreateContext();

  ImGui_Implbgfx_Init(255);
#if BX_PLATFORM_WINDOWS
  ImGui_ImplSDL2_InitForD3D(window);
#elif BX_PLATFORM_OSX
  ImGui_ImplSDL2_InitForMetal(window);
#elif BX_PLATFORM_LINUX
  ImGui_ImplSDL2_InitForOpenGL(window, nullptr);
#endif  // BX_PLATFORM_WINDOWS ? BX_PLATFORM_OSX ? BX_PLATFORM_LINUX
  const std::string shader_root = "shader/build/";

  std::string vshader;
  if (!fileops::read_file(shader_root + "v_simple.bin", vshader)) {
    printf(
        "Could not find shader vertex shader (ensure shaders have been "
        "compiled).\n"
        "Run compile-shaders-<platform>.sh/bat\n");
    return;
  }

  std::string fshader;
  if (!fileops::read_file(shader_root + "f_simple.bin", fshader)) {
    printf(
        "Could not find shader fragment shader (ensure shaders have "
        "been compiled).\n"
        "Run compile-shaders-<platform>.sh/bat\n");
    return;
  }

  // Load Textures

  AddTexture(std::make_unique<graphics::Texture>("./assets/test_textures.png"));

  vsh = CreateShader(vshader, "vshader");
  fsh = CreateShader(fshader, "fshader");

  program = bgfx::createProgram(vsh, fsh, true);
}

void RenderContext::AddTexture(std::unique_ptr<graphics::Texture> texture) {
  loaded_textures.push_back(std::move(texture));
}

graphics::Texture* RenderContext::GetTexture(uint8_t id) {
  if (loaded_textures.size() > id) {
    return loaded_textures.at(id).get();
  }
  return nullptr;
}

void RenderContext::ProgramSubmit(uint8_t id) {
  bgfx::submit(id, this->program);
}

}  // namespace game