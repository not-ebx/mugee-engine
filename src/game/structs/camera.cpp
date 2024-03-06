//
// Created by Lucas Agullo on 06-03-24.
//

#include "camera.h"
#include "../game_context.h"
#include <SDL.h>
#include <bgfx/bgfx.h>
#include <bx/math.h>

void Game::Camera::update_camera() {
    GameContext *gameContext = GameContext::get_instance();

    float cam_rotation[16];
    bx::mtxRotateXYZ(cam_rotation, pitch, yaw, 0.0f);

    float cam_translation[16];
    bx::mtxTranslate(cam_translation, pos.x, pos.y, pos.z);

    float cam_transform[16];
    bx::mtxMul(cam_transform, cam_translation, cam_rotation);

    float view[16];
    bx::mtxInverse(view, cam_transform);

    float proj[16];
    bx::mtxProj(
            proj, 60.0f, float(gameContext->getWidth()) / float(gameContext->getHeight()), 0.1f,
            100.0f, bgfx::getCaps()->homogeneousDepth);

    bgfx::setViewTransform(viewId, view, proj);

    float model[16];
    bx::mtxIdentity(model);
    bgfx::setTransform(model);
}
