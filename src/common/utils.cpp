//
// Created by Lucas Agullo on 20-03-24.
//

#include "utils.h"
#include "bgfx/bgfx.h"
#include "bx/allocator.h"
#include "bx/file.h"

namespace Common {
    bimg::ImageContainer *readImage(const std::string &filePath) {
        bx::FileReader reader;
        bx::FilePath path = filePath.c_str();
        if (!bx::open(&reader, path)) {
            return nullptr;
        }

        bx::DefaultAllocator *allocator = new bx::DefaultAllocator();

        // Get file sizes
        const uint32_t fileSize = (uint32_t) bx::getSize(&reader);
        void *data = BX_ALLOC(allocator, fileSize);
        auto err = new bx::Error();
        bx::read(&reader, data, fileSize, err);
        if (!err->isOk()) {
            return nullptr;
        }
        bx::close(&reader);

        bimg::ImageContainer imageContainer;
        bimg::imageParse(imageContainer, data, fileSize, err);
        if (!err->isOk()) {
            return nullptr;
        }

        return &imageContainer;
    }


}// namespace Common