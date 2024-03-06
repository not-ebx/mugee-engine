//
// Created by Lucas Agullo on 02-03-24.
//
#include <bgfx/bgfx.h>
#include <string>

#ifndef SDL_BGFX_IMGUI_STARTER_SHADERS_H
#define SDL_BGFX_IMGUI_STARTER_SHADERS_H


namespace Rendering
{
    bgfx::ShaderHandle create_shader(
        const std::string& shader,
        const char* name
    );
};

#endif // SDL_BGFX_IMGUI_STARTER_SHADERS_H
