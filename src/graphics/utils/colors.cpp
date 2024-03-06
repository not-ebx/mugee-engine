//
// Created by Lucas Agullo on 05-03-24.
//

#include "colors.h"

uint32_t Graphics::packRgba(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
    return (uint32_t(red) << 24) | (uint32_t(green) << 16) | (uint32_t(blue) << 8) | uint32_t(alpha);
}