//
// Created by Lucas Agullo on 05-04-24.
//

#include "block_3_d.h"
#include "../utils/helper.h"

namespace graphics {
Block3D::Block3D(TextureRegion texture_region) {
  this->triangles = GetBlockTriangles();
  this->vertices = GetBlockVertices(texture_region);
}

Block3D::Block3D(const BlockType blockId) : Block3D() {
  this->block_id = blockId;
}

Block3D* Block3D::Build(TextureRegion region) {
  auto newBlock = new Block3D(region);

  return newBlock;
}

Block3D* Block3D::CreateBlock(const BlockType blockType) {
  // TODO: Maybe there's a better way.
  this->block_id = blockType;

  this->vbh = bgfx::createVertexBuffer(
      bgfx::makeRef(vertices.data(),
                    sizeof(graphics::PosTexVertex) * vertices.size()),
      graphics::PosTexVertex::ms_layout);

  this->ibh = bgfx::createIndexBuffer(
      bgfx::makeRef(triangles.data(), sizeof(uint16_t) * triangles.size()));

  return this;
}

Block3D* Block3D::CreateBlock(const BlockType blockType, bx::Vec3 pos) {
  auto block = CreateBlock(blockType);
  block->SetGridPosition(pos);

  return this;
}

void Block3D::SetGridPosition(const bx::Vec3& position) {
  grid_pos = position;
}

bx::Vec3 Block3D::GetGridPosition() {
  return grid_pos;
}

}  // namespace graphics