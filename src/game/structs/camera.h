//
// Created by Lucas Agullo on 06-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_CAMERA_H
#define SDL_BGFX_IMGUI_STARTER_CAMERA_H

#include "../../math/vector_3.h"


namespace Game {
    struct Camera {
        float yaw = 0.0f;  //vertical axis
        float pitch = 0.0f;// horizontal axis
        float prev_mouse_x;
        float prev_mouse_y;
        Vector3 pos;

        int viewId = 0;
        void update_camera();
    };
}// namespace Game

#endif// SDL_BGFX_IMGUI_STARTER_CAMERA_H
