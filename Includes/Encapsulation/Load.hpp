/*
** EPITECH PROJECT, 2022
** Load.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_LOAD_HPP
#define BOMBERMAN_LOAD_HPP

#include "raylib.h"
#include "Objects.hpp"
#include <iostream>

namespace bomberman {
    class Load {
    public:
        // Load texture from image data
        static Texture2D loadTextureFromImage(const Image &image);

        // Load image from file into CPU memory (RAM)
        static Image loadImage(const char *fileName);

        // Load shader from files and bind default locations
        static Shader loadShader(const char *vsFileName, const char *fsFileName);

        // Load texture for rendering (framebuffer)
        static RenderTexture2D loadRenderTexture(int width, int height);

        // Load font from file with extended parameters
        static Font loadFontEx(const char *fileName, int fontSize, int *fontChars, int glyphCount);
    };
}


#endif //BOMBERMAN_LOAD_HPP
