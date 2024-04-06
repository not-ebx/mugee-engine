//
// Created by Lucas Agullo on 01-03-24.
//

#include "texture.h"

#include <SDL2_Image/SDL_image.h>
#include "../common/utils.h"

namespace graphics {
Texture::Texture(std::string texture_path) {
  load_texture(texture_path);
  // Calculate the size of the thing xd
  float horizontalTiles = surface->w / TEXTURE_DIMENSIONS;
  float tileWidth = 64.0f / surface->w;
  float verticalTiles = surface->h / TEXTURE_DIMENSIONS;
  float tileHeight = 64.0f / surface->h;

  // Generate the tilemaps

  for (float x = 0; x < horizontalTiles; x++) {
    for (float y = 0; y < verticalTiles; y++) {
      graphics::TextureRegion currRegion = {x * tileHeight, y * tileWidth,
                                            x + tileWidth, y + tileHeight};

      textureRegions.push_back(currRegion);
    }
  }

  // Determine the appropriate bgfx texture format
  bgfx::TextureFormat::Enum format = bgfx::TextureFormat::RGBA8;
  this->s_texColorUniform =
      bgfx::createUniform("s_texColor", bgfx::UniformType::Sampler);
  // Adjust this based on your SDL_Surface's format

  // Create the bgfx texture
  this->textureHandle = bgfx::createTexture2D(
      surface->w, surface->h,
      false,  // not a cube map
      1,      // number of mipmaps
      format,
      0,  // flags, e.g., BGFX_TEXTURE_NONE for no special flags
      bgfx::copy(surface->pixels, surface->w * surface->h * 4));

  //bgfx::setTexture(0, s_texColorUniform, textureHandle);
}

Texture::~Texture() {
  bgfx::destroy(this->textureHandle);
  bgfx::destroy(this->s_texColorUniform);
  SDL_FreeSurface(this->surface);
}

void Texture::load_texture(std::string texture_path) {
  SDL_Surface* loadedSurface = IMG_Load(texture_path.c_str());
  if (loadedSurface == nullptr) {
    printf("DED");
    SDL_GetError();
    return;
  }
  surface = SDL_ConvertSurfaceFormat(loadedSurface, SDL_PIXELFORMAT_RGBA32, 0);
}

void Texture::bindTexture() {
  bgfx::setTexture(
      0,  // texture stage (should match the binding point in your shader)
      this->s_texColorUniform,  // the uniform handle
      this->textureHandle       // the texture handle
  );
}

graphics::TextureRegion& Texture::getTextureRegionById(int id) {
  return textureRegions[id];
}

const bgfx::UniformHandle& Texture::getSTexColorUniform() const {
  return s_texColorUniform;
}
void Texture::setSTexColorUniform(const bgfx::UniformHandle& sTexColorUniform) {
  s_texColorUniform = sTexColorUniform;
}
const bgfx::TextureHandle& Texture::getTextureHandle() const {
  return textureHandle;
}
void Texture::setTextureHandle(const bgfx::TextureHandle& textureHandle) {
  Texture::textureHandle = textureHandle;
}
}  // namespace graphics