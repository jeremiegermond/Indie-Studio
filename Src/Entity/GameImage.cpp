/*
** EPITECH PROJECT, 2022
** GameImage.cpp
** File description:
** GameImage
*/

#include "GameImage.hpp"

namespace bomberman {
    GameImage::GameImage(const std::string &image) {
        _image = LoadImage("../Assets/Heart/life.png");
    }

    GameImage::~GameImage() {
    }
}