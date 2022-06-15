/*
** EPITECH PROJECT, 2022
** Load.cpp
** File description:
** TODO
*/

#include "Load.hpp"

namespace bomberman {

    Texture2D Load::loadTextureFromImage(const Image &image) {
        return LoadTextureFromImage(image);
    }

    Image Load::loadImage(const char *fileName) {
        return LoadImage(fileName);
    }

    Shader Load::loadShader(const char *vsFileName, const char *fsFileName) {
        return LoadShader(vsFileName, fsFileName);
    }

    RenderTexture2D Load::loadRenderTexture(int width, int height) {
        return LoadRenderTexture(width, height);
    }

    Font Load::loadFontEx(const char *fileName, int fontSize, int *fontChars, int glyphCount) {
        return LoadFontEx(fileName, fontSize, fontChars, glyphCount);
    }
}
