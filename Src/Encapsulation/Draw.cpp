/*
** EPITECH PROJECT, 2022
** Draw.cpp
** File description:
** TODO
*/

#include "Draw.hpp"
#include "Color.hpp"

namespace bomberman {
    inline void clearBackground(const MyColor &color) {
        return ClearBackground(color);
    }
    
    inline void beginDrawing(void) {
        return BeginDrawing();
    }
    
    inline void endDrawing(void) {
        return EndDrawing();
    }
    
    inline void beginMode2D(const Camera2D &camera) {
        return BeginMode2D(camera);
    }
    
    inline void endMode2D(void) {
        return EndMode2D();
    }
    
    inline void beginMode3D(const Camera3D &camera) {
        return BeginMode3D(camera);
    }
    
    inline void endMode3D(void) {
        return EndMode3D();
    }
    
    inline void beginTextureMode(const RenderTexture2D &target) {
        return BeginTextureMode(target);
    }
    
    inline void endTextureMode(void) {
        return EndTextureMode();
    }
    
    inline void beginShaderMode(const Shader &shader) {
        return BeginShaderMode(shader);
    }
    
    inline void endShaderMode(void) {
        return EndShaderMode();
    }

    static inline void draw(const std::function<void()> &function) {
        beginDrawing();
        function();
        endDrawing();
    }

    static inline void mode2D(const Camera2D &camera, const std::function<void()> &function) {
        beginMode2D(camera);
        function();
        endMode2D();
    }

    static inline void mode3D(const Camera3D &camera, const std::function<void()> &function) {
        beginMode3D(camera);
        function();
        endMode3D();
    }

    static inline void textureMode(const RenderTexture2D &texture, const std::function<void()> &function) {
        beginTextureMode(texture);
        function();
        endTextureMode();
    }

    static inline void shaderMode(const Shader &shader, const std::function<void()> &function) {
        beginShaderMode(shader);
        function();
        endShaderMode();
    }
}