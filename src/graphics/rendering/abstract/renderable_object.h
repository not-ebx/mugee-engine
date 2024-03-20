//
// Created by Lucas Agullo on 06-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_RENDERABLE_OBJECT_H
#define SDL_BGFX_IMGUI_STARTER_RENDERABLE_OBJECT_H

#include "../../../math/vector_3.h"
#include "../../structs/pos_tex_vertex.h"
#include "../../texture.h"
#include "renderable.h"
#include <bgfx/bgfx.h>
#include <vector>
namespace Rendering {
    class RenderableObject : public Renderable {
    protected:
        std::vector<Graphics::PosTexVertex> vertices;
        std::vector<uint16_t> triangles;
        bgfx::IndexBufferHandle ibh;
        bgfx::VertexBufferHandle vbh;
        Texture *texture;
        Graphics::TextureRegion *textureRegion;
        bgfx::TextureHandle textureHandle;

    public:
        virtual const std::vector<Graphics::PosTexVertex> &getVertices() const;
        void setVertices(const std::vector<Graphics::PosTexVertex> &vertices);
        virtual const std::vector<uint16_t> &getTriangles() const;
        void setTriangles(const std::vector<uint16_t> &triangles);
        virtual const bgfx::VertexBufferHandle &getVbh() const;
        virtual void setVbh(const bgfx::VertexBufferHandle &vbh);
        virtual const bgfx::IndexBufferHandle &getIbh() const;
        void setIbh(const bgfx::IndexBufferHandle &ibh);
        Texture *getTexture() const;
        void setTexture(Texture *texture);
        void setTexture(bgfx::TextureHandle handle, Graphics::TextureRegion *region);
        void setPosition(const Vector3 &position);

        void init() override;
        void update() override;
        void destroy() override;

        RenderableObject();
    };

}// namespace Rendering

#endif//SDL_BGFX_IMGUI_STARTER_RENDERABLE_OBJECT_H
