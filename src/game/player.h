//
// Created by Lucas Agullo on 06-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_PLAYER_H
#define SDL_BGFX_IMGUI_STARTER_PLAYER_H

#include "../math/vector_3.h"
#include "structs/camera.h"
#include <bgfx/bgfx.h>

namespace Game {
    class Player {
    private:
        Vector3 pos;
        Camera *camera;

    public:
        Player();
        Camera *getCamera();
        void update();
    };
}// namespace Game


#endif// SDL_BGFX_IMGUI_STARTER_PLAYER_H
