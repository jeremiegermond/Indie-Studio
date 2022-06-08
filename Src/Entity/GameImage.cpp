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

    void GameImage::DrawPlayerOne() {
        DrawTexture(_texture, _position.x, _position.y, _color);
        DrawTexture(_texture, _position.x + 100, _position.y, _color);
        DrawTexture(_texture, _position.x + 200, _position.y, _color);
    }

    void GameImage::DrawPlayerTwo() {
        DrawTexture(_texture, _position.x + 1600, _position.y, _color);
        DrawTexture(_texture, _position.x + 1700, _position.y, _color);
        DrawTexture(_texture, _position.x + 1800, _position.y, _color);
    }

    void GameImage::DrawPlayerThree() {
        DrawTexture(_texture, _position.x, _position.y + 900, _color);
        DrawTexture(_texture, _position.x + 100, _position.y + 900, _color);
        DrawTexture(_texture, _position.x + 200, _position.y + 900, _color);
    }

    void GameImage::DrawPlayerFour() {
        DrawTexture(_texture, _position.x + 1600, _position.y + 900, _color);
        DrawTexture(_texture, _position.x + 1700, _position.y + 900, _color);
        DrawTexture(_texture, _position.x + 1800, _position.y + 900, _color);
    }

    void GameImage::SetActive(bool activate) {
        active = activate;
    }
}