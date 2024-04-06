//
// Created by Lucas Agullo on 04-04-24.
//

#ifndef FUNNYGEMU_SRC_GAME_CONTEXT_RENDER_CONTEXT_H_
#define FUNNYGEMU_SRC_GAME_CONTEXT_RENDER_CONTEXT_H_

#include <SDL.h>
#include <bgfx/bgfx.h>
#include <string>
#include "../../graphics/texture.h"
namespace game {

class RenderContext {
 private:
  SDL_Window* window = nullptr;
  bgfx::ProgramHandle program = BGFX_INVALID_HANDLE;
  bgfx::ShaderHandle vsh;
  bgfx::ShaderHandle fsh;
  std::vector<std::unique_ptr<graphics::Texture>> loaded_textures;

  bgfx::ShaderHandle CreateShader(const std::string& shader, const char* name);

 public:
  RenderContext();
  void AddTexture(std::unique_ptr<graphics::Texture> texture);
  graphics::Texture* GetTexture(uint8_t id);
  void ProgramSubmit(uint8_t id);
};

}  // namespace game

#endif  //FUNNYGEMU_SRC_GAME_CONTEXT_RENDER_CONTEXT_H_
