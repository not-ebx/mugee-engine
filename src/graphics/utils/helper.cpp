//
// Created by Lucas Agullo on 05-04-24.
//

#include "helper.h"
#include "colors.h"

namespace graphics {

std::vector<PosTexVertex> GetBlockVertices(TextureRegion& region) {
  float u0 = region.u0;
  float u1 = region.u1;
  float v0 = region.v0;
  float v1 = region.v1;

  std::vector<PosTexVertex> vertices = {
      // Front face
      {-1.0f, -1.0f, 1.0f, PackRgba(255, 255, 255, 255), u0,
       v0},  // Bottom-left
      {1.0f, -1.0f, 1.0f, PackRgba(255, 255, 255, 255), u1,
       v0},                                                      // Bottom-right
      {1.0f, 1.0f, 1.0f, PackRgba(255, 255, 255, 255), u1, v1},  // Top-right
      {-1.0f, 1.0f, 1.0f, PackRgba(255, 255, 255, 255), u0, v1},  // Top-left

      // Back face
      {1.0f, -1.0f, -1.0f, PackRgba(255, 255, 255, 255), u0,
       v0},  // Bottom-right
      {-1.0f, -1.0f, -1.0f, PackRgba(255, 255, 255, 255), u1,
       v0},  // Bottom-left
      {-1.0f, 1.0f, -1.0f, PackRgba(255, 255, 255, 255), u1, v1},  // Top-left
      {1.0f, 1.0f, -1.0f, PackRgba(255, 255, 255, 255), u0, v1},   // Top-right

      // Right face
      {1.0f, -1.0f, 1.0f, PackRgba(255, 255, 255, 255), u0, v0},
      {1.0f, -1.0f, -1.0f, PackRgba(255, 255, 255, 255), u1, v0},
      {1.0f, 1.0f, -1.0f, PackRgba(255, 255, 255, 255), u1, v1},
      {1.0f, 1.0f, 1.0f, PackRgba(255, 255, 255, 255), u0, v1},

      // Left face
      {-1.0f, -1.0f, -1.0f, PackRgba(255, 255, 255, 255), u0,
       v0},  // Bottom-back
      {-1.0f, -1.0f, 1.0f, PackRgba(255, 255, 255, 255), u1,
       v0},  // Bottom-front
      {-1.0f, 1.0f, 1.0f, PackRgba(255, 255, 255, 255), u1, v1},   // Top-front
      {-1.0f, 1.0f, -1.0f, PackRgba(255, 255, 255, 255), u0, v1},  // Top-back

      // Top face
      {-1.0f, 1.0f, -1.0f, PackRgba(255, 255, 255, 255), u0, v0},  // Back-left
      {1.0f, 1.0f, -1.0f, PackRgba(255, 255, 255, 255), u1, v0},   // Back-right
      {1.0f, 1.0f, 1.0f, PackRgba(255, 255, 255, 255), u1, v1},   // Front-right
      {-1.0f, 1.0f, 1.0f, PackRgba(255, 255, 255, 255), u0, v1},  // Front-left

      // Bottom face
      {-1.0f, -1.0f, 1.0f, PackRgba(255, 255, 255, 255), u0, v0},  // Front-left
      {1.0f, -1.0f, 1.0f, PackRgba(255, 255, 255, 255), u1, v0},  // Front-right
      {1.0f, -1.0f, -1.0f, PackRgba(255, 255, 255, 255), u1, v1},  // Back-right
      {-1.0f, -1.0f, -1.0f, PackRgba(255, 255, 255, 255), u0, v1},  // Back-left
  };

  return vertices;
}

std::vector<uint16_t> GetBlockTriangles() {
  return {
      // Front face
      2, 1, 0,  // First triangle (Bottom-left, Bottom-right, Top-right)
      0, 3, 2,  // Second triangle (Top-right, Top-left, Bottom-left)

      // Back face
      6, 5, 4,  // First triangle (Bottom-right, Bottom-left, Top-left)
      4, 7, 6,  // Second triangle (Top-left, Top-right, Bottom-right)

      // Right face
      10, 9, 8,   // First triangle (Bottom-front, Bottom-back, Top-back)
      8, 11, 10,  // Second triangle (Top-back, Top-front, Bottom-front)

      // Left face
      14, 13, 12,  // First triangle (Bottom-back, Bottom-front, Top-front)
      12, 15, 14,  // Second triangle (Top-front, Top-back, Bottom-back)

      // Top face
      16, 17, 18,  // First triangle (Back-left, Back-right, Front-right)
      18, 19, 16,  // Second triangle (Front-right, Front-left, Back-left)

      // Bottom face
      20, 21, 22,  // First triangle (Front-left, Front-right, Back-right)
      22, 23, 20   // Second triangle (Back-right, Back-left, Front-left)
  };
}
}  // namespace graphics