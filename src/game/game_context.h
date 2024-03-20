//
// Created by Lucas Agullo on 06-03-24.
//

#ifndef SDL_BGFX_IMGUI_STARTER_GAME_CONTEXT_H
#define SDL_BGFX_IMGUI_STARTER_GAME_CONTEXT_H

#include "../graphics/block_3_d.h"
#include "../graphics/rendering/abstract/renderable_object.h"
#include "player.h"
#include "structs/camera.h"
#include <SDL.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/platform.h>
#include <vector>

namespace Game {
    class GameContext {
    private:
        SDL_Window *window = nullptr;
        bgfx::ProgramHandle program = BGFX_INVALID_HANDLE;
        bgfx::ShaderHandle vsh;
        bgfx::ShaderHandle fsh;
        int width = 0;
        int height = 0;
        bool quit = false;
        Player *player;
        std::vector<std::shared_ptr<Texture>> loadedTextures;

        GameContext();

        static GameContext *instance;

    public:
        static GameContext *get_instance();
        ~GameContext();
        SDL_Window *getWindow() const;
        Texture *getLoadedTexture(int i);
        Rendering::RenderableObject *getRenderableObject(int id);
        void setWindow(SDL_Window *window);
        const bgfx::ProgramHandle &getProgram() const;
        void setProgram(const bgfx::ProgramHandle &program);
        const bgfx::ShaderHandle &getVsh() const;
        void setVsh(const bgfx::ShaderHandle &vsh);
        const bgfx::ShaderHandle &getFsh() const;
        void setFsh(const bgfx::ShaderHandle &fsh);
        int getWidth() const;
        void setWidth(int width);
        int getHeight() const;
        void setHeight(int height);
        bool isQuit() const;
        void setQuit(bool quit);
        Camera *getCamera();
        Player *getPlayer();

        // TEMP STUFF
        std::vector<Block3D *> cubeQueue;
    };

}// namespace Game

#endif//SDL_BGFX_IMGUI_STARTER_GAME_CONTEXT_H
