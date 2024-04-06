//
// Created by Lucas Agullo on 20-03-24.
//

#ifndef UTILS_H
#define UTILS_H

#include <bimg/bimg.h>
#include <string>

namespace common {

bimg::ImageContainer* ReadImage(const std::string& filePath);
}  // namespace common

#endif  //UTILS_H
