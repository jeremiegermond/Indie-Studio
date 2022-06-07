/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** GameButton
*/

#include "GameButton.hpp"

bomberman::GameButton::GameButton(std::string texturePath, int x, int y, int width, int height)
{
    _button = LoadTexture(texturePath.c_str());
    _bounds = new MyRectangle(x, y, width, height);
}

bomberman::GameButton::~GameButton()
{
}
