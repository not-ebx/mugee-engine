//
// Created by Lucas Agullo on 02-03-24.
//

#include "shaders.h"

namespace Rendering {
    bgfx::ShaderHandle create_shader(
        const std::string& shader, const char* name)
    {
        const bgfx::Memory* mem = bgfx::copy(shader.data(), shader.size());
        const bgfx::ShaderHandle handle = bgfx::createShader(mem);
        bgfx::setName(handle, name);
        return handle;
    }
}
