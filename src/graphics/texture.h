//
// Created by Lucas Agullo on 01-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_TEXTURE_H
#define SDL_BGFX_IMGUI_STARTER_TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <bgfx/bgfx.h>

class Texture {
private:
    bgfx::UniformHandle s_texColorUniform;
    bgfx::TextureHandle textureHandle;
    SDL_Surface* surface;
    void load_texture(std::string texture_path);

public:
    Texture(std::string texture_path);
    ~Texture();
    const bgfx::UniformHandle& getSTexColorUniform() const;
    void setSTexColorUniform(const bgfx::UniformHandle& sTexColorUniform);
    const bgfx::TextureHandle& getTextureHandle() const;
    void setTextureHandle(const bgfx::TextureHandle& textureHandle);
    void bindTexture();
};

#endif // SDL_BGFX_IMGUI_STARTER_TEXTURE_H
