/*
** EPITECH PROJECT, 2022
** GameImage.cpp
** File description:
** GameImage
*/

#include "GameImage.hpp"

namespace bomberman {
    GameImage::GameImage(const std::string &image, float x, float y, MyColor color) {
        _image = LoadImage(image.c_str());
        _texture = LoadTextureFromImage(_image);
        _position.x = x;
        _position.y = y;
        _color = color;
        UnloadImage(_image);
    }

    void GameImage::Draw() {
        DrawTexture(_texture, _position.x, _position.y, _color);
        DrawTexture(_texture, _position.x + 100, _position.y, _color);
        DrawTexture(_texture, _position.x + 200, _position.y, _color);
    }

    void GameImage::SetActive(bool activate) {
        active = activate;
    }
}