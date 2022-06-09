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
}
