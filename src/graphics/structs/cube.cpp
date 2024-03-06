//
// Created by Lucas Agullo on 05-03-24.
//

#include "cube.h"
namespace Graphics {
    Cube::Cube() {
        vertices = {
            // Front face
            {-1.0f, -1.0f, 1.0f, packRgba(255, 0, 0, 255), 0.0f,
             0.0f}, // Bottom-left
            {1.0f, -1.0f, 1.0f, packRgba(255, 0, 0, 255), 1.0f,
             0.0f}, // Bottom-right
            {1.0f, 1.0f, 1.0f, packRgba(255, 0, 0, 255), 1.0f,
             1.0f}, // Top-right
            {-1.0f, 1.0f, 1.0f, packRgba(255, 0, 0, 255), 0.0f,
             1.0f}, // Top-left

            // Back face
            {1.0f, -1.0f, -1.0f, packRgba(0, 255, 0, 255), 0.0f,
             0.0f}, // Bottom-right
            {-1.0f, -1.0f, -1.0f, packRgba(0, 255, 0, 255), 1.0f,
             0.0f}, // Bottom-left
            {-1.0f, 1.0f, -1.0f, packRgba(0, 255, 0, 255), 1.0f,
             1.0f}, // Top-left
            {1.0f, 1.0f, -1.0f, packRgba(0, 255, 0, 255), 0.0f,
             1.0f}, // Top-right

            // Right face
            {1.0f, -1.0f, 1.0f, packRgba(0, 0, 255, 255), 0.0f,
             0.0f}, // Bottom-front
            {1.0f, -1.0f, -1.0f, packRgba(0, 0, 255, 255), 1.0f,
             0.0f}, // Bottom-back
            {1.0f, 1.0f, -1.0f, packRgba(0, 0, 255, 255), 1.0f,
             1.0f}, // Top-back
            {1.0f, 1.0f, 1.0f, packRgba(0, 0, 255, 255), 0.0f,
             1.0f}, // Top-front

            // Left face
            {-1.0f, -1.0f, -1.0f, packRgba(255, 255, 0, 255), 0.0f,
             0.0f}, // Bottom-back
            {-1.0f, -1.0f, 1.0f, packRgba(255, 255, 0, 255), 1.0f,
             0.0f}, // Bottom-front
            {-1.0f, 1.0f, 1.0f, packRgba(255, 255, 0, 255), 1.0f,
             1.0f}, // Top-front
            {-1.0f, 1.0f, -1.0f, packRgba(255, 255, 0, 255), 0.0f,
             1.0f}, // Top-back

            // Top face
            {-1.0f, 1.0f, -1.0f, packRgba(255, 0, 255, 255), 0.0f,
             0.0f}, // Back-left
            {1.0f, 1.0f, -1.0f, packRgba(255, 0, 255, 255), 1.0f,
             0.0f}, // Back-right
            {1.0f, 1.0f, 1.0f, packRgba(255, 0, 255, 255), 1.0f,
             1.0f}, // Front-right
            {-1.0f, 1.0f, 1.0f, packRgba(255, 0, 255, 255), 0.0f,
             1.0f}, // Front-left

            // Bottom face
            {-1.0f, -1.0f, 1.0f, packRgba(0, 255, 255, 255), 0.0f,
             0.0f}, // Front-left
            {1.0f, -1.0f, 1.0f, packRgba(0, 255, 255, 255), 1.0f,
             0.0f}, // Front-right
            {1.0f, -1.0f, -1.0f, packRgba(0, 255, 255, 255), 1.0f,
             1.0f}, // Back-right
            {-1.0f, -1.0f, -1.0f, packRgba(0, 255, 255, 255), 0.0f,
             1.0f}, // Back-left
        };
        triangles = {
            // Front face
            2, 1, 0, // First triangle (Bottom-left, Bottom-right, Top-right)
            0, 3, 2, // Second triangle (Top-right, Top-left, Bottom-left)

            // Back face
            6, 5, 4, // First triangle (Bottom-right, Bottom-left, Top-left)
            4, 7, 6, // Second triangle (Top-left, Top-right, Bottom-right)

            // Right face
            10, 9, 8, // First triangle (Bottom-front, Bottom-back, Top-back)
            8, 11, 10, // Second triangle (Top-back, Top-front, Bottom-front)

            // Left face
            14, 13, 12, // First triangle (Bottom-back, Bottom-front, Top-front)
            12, 15, 14, // Second triangle (Top-front, Top-back, Bottom-back)

            // Top face
            16, 17, 18, // First triangle (Back-left, Back-right, Front-right)
            18, 19, 16, // Second triangle (Front-right, Front-left, Back-left)

            // Bottom face
            20, 21, 22, // First triangle (Front-left, Front-right, Back-right)
            22, 23, 20 // Second triangle (Back-right, Back-left, Front-left)
        };

        vbh = bgfx::createVertexBuffer(
            bgfx::makeRef(
                vertices.data(),
                sizeof(Graphics::PosTexVertex) * vertices.size()
                    ),
            Graphics::PosTexVertex::ms_layout
        );
        ibh = bgfx::createIndexBuffer(
            bgfx::makeRef(
                triangles.data(),
                sizeof(uint16_t) * triangles.size()
                    )
        );
    }

    Cube::Cube(Texture* tex) : Cube() {
        texture = tex;
        //texture->bindTexture();
    }

    Cube::~Cube() {
        bgfx::destroy(vbh);
        bgfx::destroy(ibh);
        delete texture;
        vertices.clear();
        triangles.clear();
    }

    void Cube::setPosition(const Vector3& position) {
        for (PosTexVertex& vertex : vertices) {
            vertex.x += position.x;
            vertex.y += position.y;
            vertex.z += position.z;
        }
    }

    void Cube::render() {
        texture->bindTexture();
    }


    // === Getters and Setters ====
    const std::vector<PosTexVertex>& Cube::getVertices() const
    {
        return vertices;
    }
    void Cube::setVertices(const std::vector<PosTexVertex>& vertices)
    {
        Cube::vertices = vertices;
    }
    const std::vector<uint16_t>& Cube::getTriangles() const
    {
        return triangles;
    }
    void Cube::setTriangles(const std::vector<uint16_t>& triangles)
    {
        Cube::triangles = triangles;
    }
    const bgfx::VertexBufferHandle& Cube::getVbh() const
    {
        return vbh;
    }
    void Cube::setVbh(const bgfx::VertexBufferHandle& vbh)
    {
        Cube::vbh = vbh;
    }
    const bgfx::IndexBufferHandle& Cube::getIbh() const
    {
        return ibh;
    }
    void Cube::setIbh(const bgfx::IndexBufferHandle& ibh)
    {
        Cube::ibh = ibh;
    }
    Texture* Cube::getTexture() const
    {
        return texture;
    }
    void Cube::setTexture(Texture* texture)
    {
        Cube::texture = texture;
    }
}