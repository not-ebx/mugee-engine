//
// Created by Lucas Agullo on 01-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_TEXTURE_H
#define SDL_BGFX_IMGUI_STARTER_TEXTURE_H

#include "structs/texture_region.h"
#include <SDL.h>
#include <bgfx/bgfx.h>
#include <string>
#include <vector>

const int TEXTURE_DIMENSIONS = 64;


class Texture {
private:
    bgfx::UniformHandle s_texColorUniform;
    bgfx::TextureHandle textureHandle;
    SDL_Surface *surface;
    void load_texture(std::string texture_path);
    std::vector<Graphics::TextureRegion> textureRegions;

public:
    Texture(std::string texture_path);
    ~Texture();
    const bgfx::UniformHandle &getSTexColorUniform() const;
    void setSTexColorUniform(const bgfx::UniformHandle &sTexColorUniform);
    const bgfx::TextureHandle &getTextureHandle() const;
    void setTextureHandle(const bgfx::TextureHandle &textureHandle);
    void bindTexture();
    Graphics::TextureRegion &getTextureRegionById(int id);
};

#endif// SDL_BGFX_IMGUI_STARTER_TEXTURE_H
