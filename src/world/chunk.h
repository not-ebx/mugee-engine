//
// Created by Lucas Agullo on 05-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_CHUNK_H
#define SDL_BGFX_IMGUI_STARTER_CHUNK_H

#include "../graphics/structs/cube.h"
#include "../math/vector_3.h"
#include <vector>

class Chunk {
private:
    Vector3 position;
    std::vector<Graphics::Cube> cubes;

public:
    void initialize(int cubesPerAxis, const Vector3& pos) {

    }
};

#endif // SDL_BGFX_IMGUI_STARTER_CHUNK_H
