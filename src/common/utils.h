//
// Created by Lucas Agullo on 20-03-24.
//

#ifndef UTILS_H
#define UTILS_H
#include "../graphics/block_3_d.h"

#include <bimg/bimg.h>

namespace Common {

    bimg::ImageContainer *readImage(const std::string &filePath);
}// namespace Common

#endif//UTILS_H
