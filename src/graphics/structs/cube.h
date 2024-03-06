//
// Created by Lucas Agullo on 05-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_CUBE_H
#define SDL_BGFX_IMGUI_STARTER_CUBE_H

#include "../../math/vector_3.h"
#include "../texture.h"
#include "../utils/colors.h"
#include "pos_tex_vertex.h"
#include <bgfx/bgfx.h>
#include <vector>

namespace Graphics {
    class Cube {
    private:
        std::vector<PosTexVertex> vertices;
        std::vector<uint16_t> triangles;
        bgfx::VertexBufferHandle vbh;
        bgfx::IndexBufferHandle ibh;
        Texture* texture;

    public:
        Cube();
        Cube(Texture* tex);
        ~Cube();
        const bgfx::VertexBufferHandle& getVbh() const;
        void setVbh(const bgfx::VertexBufferHandle& vbh);
        const bgfx::IndexBufferHandle& getIbh() const;
        void setIbh(const bgfx::IndexBufferHandle& ibh);
        Texture* getTexture() const;
        void setTexture(Texture* texture);
        void render();
        Cube(std::vector<PosTexVertex> vertices, std::vector<uint16_t> triangles);
        void setPosition(const Vector3& position);
        const std::vector<PosTexVertex>& getVertices() const;
        void setVertices(const std::vector<PosTexVertex>& vertices);
        const std::vector<uint16_t>& getTriangles() const;
        void setTriangles(const std::vector<uint16_t>& triangles);
    };
}

#endif // SDL_BGFX_IMGUI_STARTER_CUBE_H
