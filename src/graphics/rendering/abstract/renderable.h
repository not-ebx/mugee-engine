//
// Created by Lucas Agullo on 06-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_RENDERABLE_H
#define SDL_BGFX_IMGUI_STARTER_RENDERABLE_H

namespace Rendering {
    class Renderable {
    public:
        virtual ~Renderable() {}
        virtual void update() = 0;
        virtual void init() = 0;
        virtual void destroy() = 0;
    };
}// namespace Rendering


#endif//SDL_BGFX_IMGUI_STARTER_RENDERABLE_H
