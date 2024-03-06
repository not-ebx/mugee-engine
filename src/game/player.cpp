//
// Created by Lucas Agullo on 06-03-24.
//

#include "player.h"
#include <SDL_keyboard.h>
#include <SDL_mouse.h>
#include <SDL_scancode.h>
#include <imgui.h>

const float ROT_SCALE = 0.05f;

namespace Game {
    Player::Player() {
        pos = *new Vector3({0, 0, 0});
        camera = static_cast<Camera *>(malloc(sizeof(Camera)));
        camera->pos = {0, 0, 0};
    }
    Camera *Player::getCamera() {
        return camera;
    }

    void Player::update() {

        if (!ImGui::GetIO().WantCaptureMouse) {
            // simple input code for orbit camera
            int mouse_x, mouse_y;
            const int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
            if ((buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0) {
                int delta_x = mouse_x - camera->prev_mouse_x;
                int delta_y = mouse_y - camera->prev_mouse_y;
                camera->yaw += float(-delta_x) * ROT_SCALE;
                camera->pitch += float(-delta_y) * ROT_SCALE;
            }
            camera->prev_mouse_x = mouse_x;
            camera->prev_mouse_y = mouse_y;
        }

        if (!ImGui::GetIO().WantCaptureKeyboard) {
            const Uint8 *keyboardInput = SDL_GetKeyboardState(NULL);
            if (keyboardInput[SDL_SCANCODE_W]) {
                camera->pos += {0, 0, 0.1f};
            }
            if (keyboardInput[SDL_SCANCODE_S]) {
                camera->pos += {0, 0, -0.1f};
            }
            if (keyboardInput[SDL_SCANCODE_D]) {
                camera->pos += {0.1f, 0, 0};
            }
            if (keyboardInput[SDL_SCANCODE_A]) {
                camera->pos += {-0.1f, 0, 0};
            }
        }
        camera->update_camera();
    }
}// namespace Game