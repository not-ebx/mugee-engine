//
// Created by Lucas Agullo on 05-04-24.
//

#include "object_factory.h"

namespace world {

graphics::Block3D* CreateObject(game::GameStateManager* ctx,
                                const BlockType blockType) {
  // TODO add details about the blocks :)
  // TODO: Maybe there's a better way.
  auto textureRef = ctx->GetRenderContext()->GetTexture(0);

  graphics::TextureRegion region;
  switch (blockType) {
    case BlockType::DIRT:
      region = textureRef->getTextureRegionById(0);
      break;
    case BlockType::BRICKS:
      region = textureRef->getTextureRegionById(1);
      break;
  }

  BlockType blockId = blockType;

  return graphics::Block3D::Build(region)->CreateBlock(blockType);
}

graphics::Block3D* CreateObject(game::GameStateManager* ctx,
                                const BlockType blockType, bx::Vec3 pos) {
  // TODO add details about the blocks :)
  auto block = CreateObject(ctx, blockType);
  block->SetGridPosition(pos);
  return block;
}

}  // namespace world