//
// Created by Lucas Agullo on 05-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_VECTOR_3_H
#define SDL_BGFX_IMGUI_STARTER_VECTOR_3_H

#pragma once
#include <cmath>

class Vector3
{
public:
    float x, y, z;

    Vector3();
    Vector3(float x, float y, float z);

    Vector3 operator+(const Vector3& other) const;
    Vector3& operator+=(const Vector3& other);
    Vector3 operator-(const Vector3& other) const;
    Vector3& operator-=(const Vector3& other);
    Vector3 operator*(float scalar) const;
    Vector3& operator*=(float scalar);
    Vector3 operator/(float scalar) const;
    Vector3& operator/=(float scalar);

    float Magnitude() const;
    Vector3 Normalize() const;
    float Dot(const Vector3& other) const;
    Vector3 Cross(const Vector3& other) const;

    static Vector3 Zero();
};

#endif // SDL_BGFX_IMGUI_STARTER_VECTOR_3_H
