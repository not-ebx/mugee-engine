//
// Created by Lucas Agullo on 06-03-24.
//

#include "player.h"

#include <SDL_keyboard.h>
#include <SDL_mouse.h>
#include <SDL_scancode.h>
#include <bx/math.h>
#include <imgui.h>

const float ROT_SCALE = 0.05f;

namespace world {

Player::Player() {
  camera = std::make_unique<Camera>();
}

Camera* Player::GetCamera() {
  return camera.get();
}

bx::Vec3 Player::GetGridPosition() {
  // TODO set those values on a const
  uint width = 64;
  uint height = 256;

  return {trunc(pos.x / width), trunc(pos.y / height), trunc(pos.z / width)};
}

void Player::Update() {
  bx::Vec3 oldPos = {camera->pos.x, camera->pos.y, camera->pos.z};
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
    const Uint8* keyboardInput = SDL_GetKeyboardState(NULL);

    // Adjust camera position based on the keyboard input
    float moveSpeed = 0.1f;
    if (keyboardInput[SDL_SCANCODE_W]) {
      // Move forward: Increase pos in the direction the camera is facing
      camera->pos = bx::add(camera->pos, bx::mul(camera->forward, moveSpeed));
    }
    if (keyboardInput[SDL_SCANCODE_S]) {
      // Move backward: Decrease pos in the direction the camera is facing
      camera->pos = bx::sub(camera->pos, bx::mul(camera->forward, moveSpeed));
    }
    if (keyboardInput[SDL_SCANCODE_D]) {
      // Move left: Decrease pos in the right direction (hence, moving left)
      camera->pos = bx::sub(camera->pos, bx::mul(camera->right, moveSpeed));
    }
    if (keyboardInput[SDL_SCANCODE_A]) {
      // Move right: Increase pos in the right direction
      camera->pos = bx::add(camera->pos, bx::mul(camera->right, moveSpeed));
    }
  }

  if (!isEqual(oldPos, camera->pos, 0.01)) {
    this->SetPosition(camera->pos);
    /*
    if (IsColliding()) {
      this->SetPosition(oldPos);
      camera->pos = oldPos;
    }*/
    camera->update_camera();
    // Update chunks around player.
    auto gridPos = GetGridPosition();

    // TODO: Have to update grid blocks
    //this->world->getWorldGrid(gridPos).update();
    //this->world.get()->render();
  }
  printf("PLAYER POS: x:%f, y:%f, z:%f\n", pos.x, pos.y, pos.z);
}
}  // namespace world