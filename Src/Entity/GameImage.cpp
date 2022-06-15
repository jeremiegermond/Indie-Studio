/*
** EPITECH PROJECT, 2022
** GameImage.cpp
** File description:
** GameImage
*/

#include "GameImage.hpp"

namespace bomberman {
    GameImage::GameImage(const std::string &image, int x, int y, MyColor color) {
        _texture = Load::loadTexture(image.c_str());
        posX = x;
        posY = y;
        _color = color;
        active = true;
    }

    void GameImage::Draw() {
        if (active)
            Draw::drawTexture(_texture, posX, posY, _color);
    }

    void GameImage::SetActive(bool activate) {
        active = activate;
    }

    void GameImage::SetColor(MyColor color) {
        _color = color;
    }
}