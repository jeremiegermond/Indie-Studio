/*
** EPITECH PROJECT, 2022
** Draw.hpp
** File description:
** TODO
*/

#pragma once

#include "raylib.h"
#include <functional>
#include <iostream>

namespace bomberman {
    class Draw {
    public:
        Draw();
        ~Draw();
        // Set background color (framebuffer clear color)
        inline void clearBackground(Color color);

        // Setup canvas (framebuffer) to start drawing
        inline void beginDrawing(void);

        // End canvas drawing and swap buffers (double buffering)
        inline void endDrawing(void);

        // Begin 2D mode with custom camera (2D)
        inline void beginMode2D(Camera2D camera);

        // Ends 2D mode with custom camera
        inline void endMode2D(void);

        // Begin 3D mode with custom camera (3D)
        inline void beginMode3D(Camera3D camera);

        // Ends 3D mode and returns to default 2D orthographic mode
        inline void endMode3D(void);

        // Begin drawing to render texture
        inline void beginTextureMode(RenderTexture2D target);

        // Ends drawing to render texture
        inline void endTextureMode(void);

        // Begin custom shader drawing
        inline void beginShaderMode(Shader shader);

        // End custom shader drawing (use default shader)
        inline void endShaderMode(void);

        //additional function: draw
        static inline void draw(const std::function<void()> &function);

        //additional function: mode2D
        static inline void mode2D(const Camera2D &camera, const std::function<void()> &function);

        //additional function: mode3D
        static inline void mode3D(const Camera3D &camera, const std::function<void()> &function);

        //additional function: textureMode
        static inline void textureMode(const RenderTexture2D &texture, const std::function<void()> &function);

        //additional function: shaderMode
        static inline void shaderMode(const Shader &shader, const std::function<void()> &function);
    };
}
