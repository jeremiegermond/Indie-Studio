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
        static inline Texture2D loadTextureFromImage(const Image &image);

        // Load image from file into CPU memory (RAM)
        static inline Image loadImage(const char *fileName);
    };
}


#endif //BOMBERMAN_LOAD_HPP
