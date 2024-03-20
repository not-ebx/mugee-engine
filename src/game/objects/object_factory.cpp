//
// Created by Lucas Agullo on 11-03-24.
//

#include "object_factory.h"

Block3D *ObjectFactory::createObject(const BlockType blockType) {
    // TODO add details about the blocks :)
    return Block3D::build()->createBlock(blockType);
}