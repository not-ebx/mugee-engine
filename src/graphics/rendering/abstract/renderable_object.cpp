//
// Created by Lucas Agullo on 06-03-24.
//

#include "renderable_object.h"
namespace Rendering {

    void RenderableObject::setTexture(bgfx::TextureHandle handle, Graphics::TextureRegion *region) {
        textureHandle = handle;
        textureRegion = region;
    }

    const std::vector<Graphics::PosTexVertex> &RenderableObject::getVertices() const {
        return vertices;
    }
    void RenderableObject::setVertices(const std::vector<Graphics::PosTexVertex> &vertices) {
        RenderableObject::vertices = vertices;
    }
    const std::vector<uint16_t> &RenderableObject::getTriangles() const {
        return triangles;
    }
    void RenderableObject::setTriangles(const std::vector<uint16_t> &triangles) {
        RenderableObject::triangles = triangles;
    }
    const bgfx::VertexBufferHandle &RenderableObject::getVbh() const {
        return vbh;
    }
    void RenderableObject::setVbh(const bgfx::VertexBufferHandle &vbh) {
        RenderableObject::vbh = vbh;
    }
    const bgfx::IndexBufferHandle &RenderableObject::getIbh() const {
        return ibh;
    }
    void RenderableObject::setIbh(const bgfx::IndexBufferHandle &ibh) {
        RenderableObject::ibh = ibh;
    }
    Texture *RenderableObject::getTexture() const {
        return texture;
    }
    void RenderableObject::setTexture(Texture *texture) {
        RenderableObject::texture = texture;
    }

    void RenderableObject::setPosition(const Vector3 &position) {
        for (Graphics::PosTexVertex &vertex: vertices) {
            vertex.x += position.x;
            vertex.y += position.y;
            vertex.z += position.z;
        }
    }

    RenderableObject::RenderableObject() {
    }

    void RenderableObject::init() {
        return;
    }

    void RenderableObject::update() {
        return;
    }

    void RenderableObject::destroy() {
        return;
    }

}// namespace Rendering