//
// Created by Lucas Agullo on 11-03-24.
//

#include "block_3d.h"

#include "../game_context.h"

Block3D::Block3D() {}

Block3D::Block3D(const BlockType blockId) : Block3D() {
    this->blockId = blockId;
}

Block3D *Block3D::build() {
    return new Block3D();
}

Block3D *Block3D::createBlock(const BlockType blockType) {
    // TODO: Maybe there's a better way.
    auto textureRef = Game::GameContext::get_instance()->getLoadedTexture(0);

    Graphics::TextureRegion region;
    switch (blockType) {
        case BlockType::DIRT:
            region = textureRef->getTextureRegionById(0);
            break;
        case BlockType::BRICKS:
            region = textureRef->getTextureRegionById(1);
            break;
    }

    this->blockId = blockId;
    this->triangles = Graphics::getBlockTriangles();
    this->vertices = Graphics::getBlockVertices(region);

    this->vbh = bgfx::createVertexBuffer(
            bgfx::makeRef(
                    vertices.data(),
                    sizeof(Graphics::PosTexVertex) * vertices.size()),
            Graphics::PosTexVertex::ms_layout);

    this->ibh = bgfx::createIndexBuffer(
            bgfx::makeRef(
                    triangles.data(),
                    sizeof(uint16_t) * triangles.size()));

    return this;
}

void Block3D::setGridPosition(const Vector3 &position) {
    gridPos = position;
}

Vector3 Block3D::getGridPosition() {
    return gridPos;
}
