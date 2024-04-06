//
// Created by Lucas Agullo on 05-04-24.
//

#ifndef FUNNYGEMU_SRC_GRAPHICS_UTILS_HELPER_H_
#define FUNNYGEMU_SRC_GRAPHICS_UTILS_HELPER_H_

#include <vector>
#include "../structs/pos_tex_vertex.h"
#include "../structs/texture_region.h"

namespace graphics {
std::vector<PosTexVertex> GetBlockVertices(TextureRegion& region);
std::vector<uint16_t> GetBlockTriangles();
};  // namespace graphics

#endif  //FUNNYGEMU_SRC_GRAPHICS_UTILS_HELPER_H_
