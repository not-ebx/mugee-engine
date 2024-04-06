//
// Created by Lucas Agullo on 06-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_CAMERA_H
#define SDL_BGFX_IMGUI_STARTER_CAMERA_H

#include <bx/math.h>

namespace world {
class Camera {
 public:
  float yaw = 0.0f;    //vertical axis
  float pitch = 0.0f;  // horizontal axis
  float prev_mouse_x;
  float prev_mouse_y;
  bx::Vec3 pos = {0, 0, 0};
  bx::Vec3 forward = {0, 0, 0};
  bx::Vec3 right = {0, 0, 0};
  bx::Vec3 up = {0, 0, 0};

  int viewId = 0;
  Camera();
  void update_camera();
};
}  // namespace world

#endif  // SDL_BGFX_IMGUI_STARTER_CAMERA_H
