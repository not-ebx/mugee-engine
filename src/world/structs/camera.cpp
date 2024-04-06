//
// Created by Lucas Agullo on 06-03-24.
//

#include "camera.h"
#include <bgfx/bgfx.h>
#include <bx/math.h>

world::Camera::Camera() {

  pos = {0, 0, 0};
  forward = {0, 0, 0};
  right = {0, 0, 0};
  up = {0, 0, 0};
}

void world::Camera::update_camera() {

  // First, create a rotation matrix based on the camera's pitch and yaw
  float cam_rotation[16];
  bx::mtxRotateXYZ(cam_rotation, pitch, yaw, 0.0f);

  forward = {-cam_rotation[8], -cam_rotation[9], -cam_rotation[10]};
  right = {cam_rotation[0], cam_rotation[1], cam_rotation[2]};
  up = {cam_rotation[4], cam_rotation[5], cam_rotation[6]};

  // Then, create a translation matrix based on the camera's position
  float cam_translation[16];
  bx::mtxTranslate(cam_translation, -pos.x, -pos.y, -pos.z);

  // Combine the rotation and translation matrices
  // Notice that the translation is applied AFTER the rotation
  float cam_transform[16];
  bx::mtxMul(cam_transform, cam_rotation, cam_translation);

  // Calculate the view matrix as the inverse of the camera transformation matrix
  float view[16];
  bx::mtxInverse(view, cam_transform);

  // Set up the projection matrix
  float proj[16];
  bx::mtxProj(proj, 60.0f, float(1280) / float(720), 0.1f, 100.0f,
              bgfx::getCaps()->homogeneousDepth);

  // Set the view and projection matrices for rendering
  bgfx::setViewTransform(viewId, view, proj);

  // The model matrix is set to identity as it's not used here for camera transformation
  float model[16];
  bx::mtxIdentity(model);
  bgfx::setTransform(model);
}
