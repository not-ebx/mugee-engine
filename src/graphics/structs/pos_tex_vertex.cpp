//
// Created by Lucas Agullo on 02-03-24.
//

#include "pos_tex_vertex.h"

namespace graphics {
bgfx::VertexLayout PosTexVertex::ms_layout;  // Definition

void PosTexVertex::init() {
  ms_layout.begin()
      .add(bgfx::Attrib::Position, 3,
           bgfx::AttribType::Float)  // 3 floats for x, y, z
      .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8,
           true)  // 4 bytes for RGBA color, normalized
      .add(bgfx::Attrib::TexCoord0, 2,
           bgfx::AttribType::Float)  // 2 floats for u, v texture coordinates
      .end();
}
}  // namespace graphics