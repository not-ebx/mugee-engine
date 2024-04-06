//
// Created by Lucas Agullo on 01-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_TEXTURE_H
#define SDL_BGFX_IMGUI_STARTER_TEXTURE_H

#include <SDL.h>
#include <bgfx/bgfx.h>
#include <string>
#include <vector>
#include "structs/texture_region.h"

const int TEXTURE_DIMENSIONS = 64;

namespace graphics {
class Texture {
 private:
  bgfx::UniformHandle s_texColorUniform;
  bgfx::TextureHandle textureHandle;
  SDL_Surface* surface;
  void load_texture(std::string texture_path);
  std::vector<TextureRegion> textureRegions;

 public:
  Texture(std::string texture_path);
  ~Texture();
  const bgfx::UniformHandle& getSTexColorUniform() const;
  void setSTexColorUniform(const bgfx::UniformHandle& sTexColorUniform);
  const bgfx::TextureHandle& getTextureHandle() const;
  void setTextureHandle(const bgfx::TextureHandle& textureHandle);
  void bindTexture();
  graphics::TextureRegion& getTextureRegionById(int id);
};
}  // namespace graphics
#endif  // SDL_BGFX_IMGUI_STARTER_TEXTURE_H
