//
// Created by Lucas Agullo on 07-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_TEXTURE_REGION_H
#define SDL_BGFX_IMGUI_STARTER_TEXTURE_REGION_H

namespace graphics {
struct TextureRegion {
  float u0, v0;  // Top-left UV coordinates
  float u1, v1;  // Bottom-right UV coordinates
};
}  // namespace graphics

#endif  //SDL_BGFX_IMGUI_STARTER_TEXTURE_REGION_H
