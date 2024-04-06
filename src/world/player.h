//
// Created by Lucas Agullo on 06-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_PLAYER_H
#define SDL_BGFX_IMGUI_STARTER_PLAYER_H

#include <bgfx/bgfx.h>
#include <sys/types.h>
#include <vector>
#include "structs/camera.h"

namespace world {
class Player {
 private:
  bx::Vec3 pos = {0, 0, 0};
  std::unique_ptr<Camera> camera;
  uint renderDistance = 10;

 public:
  Player();
  bx::Vec3 GetPosition() { return pos; };
  bx::Vec3 GetGridPosition();
  void SetPosition(bx::Vec3 newPos) { pos = newPos; }
  Camera* GetCamera();
  void Update();
};
}  // namespace world

#endif  // SDL_BGFX_IMGUI_STARTER_PLAYER_H
