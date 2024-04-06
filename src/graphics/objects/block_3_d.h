//
// Created by Lucas Agullo on 05-04-24.
//

#ifndef FUNNYGEMU_SRC_GRAPHICS_OBJECTS_BLOCK_3_D_H_
#define FUNNYGEMU_SRC_GRAPHICS_OBJECTS_BLOCK_3_D_H_

#include <bx/math.h>
#include <vector>
#include "../enum/block_data.h"
#include "../structs/pos_tex_vertex.h"
#include "../structs/texture_region.h"

namespace graphics {

class Block3D {
 private:
  BlockType block_id;
  std::vector<PosTexVertex> vertices;
  bgfx::VertexBufferHandle vbh;
  bgfx::IndexBufferHandle ibh;
  std::vector<uint16_t> triangles;
  bx::Vec3 grid_pos = {0, 0, 0};
  uint8_t size = 2;

 public:
  Block3D(TextureRegion texture_region);
  Block3D() = default;
  Block3D(const BlockType blockId);
  static Block3D* Build(TextureRegion region);
  Block3D* CreateBlock(BlockType blockId);
  Block3D* CreateBlock(BlockType blockType, bx::Vec3 pos);
  void SetGridPosition(const bx::Vec3& position);
  bx::Vec3 GetGridPosition();
  uint8_t GetSize() { return size; };
  bgfx::VertexBufferHandle GetVbh() { return vbh; }
  bgfx::IndexBufferHandle GetIbh() { return ibh; }
};

}  // namespace graphics

#endif  //FUNNYGEMU_SRC_GRAPHICS_OBJECTS_BLOCK_3_D_H_
