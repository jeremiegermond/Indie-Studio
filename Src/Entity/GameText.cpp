/*
** EPITECH PROJECT, 2022
** GameText.cpp
** File description:
** GameText
*/

#include "GameText.hpp"

namespace bomberman {
    GameText::GameText(const std::string &font, const std::string &msg, float x, float y, float fontSize, Color color, bool flash)
    {
        _fontSize = fontSize;
        _font = LoadFontEx(font.c_str(), _fontSize, 0, 250);
        _msg = msg;
        _fontPosition.x = x;
        _fontPosition.y = y;
        _color = color;
    }

    GameText::~GameText()
    {
    }

    void GameText::Draw()
    {
        DrawTextEx(_font, _msg.c_str(), _fontPosition, _fontSize, 0, _color);
    }

    void GameText::Update()
    {
    }

    void GameText::SetActive(bool activate)
    {
        active = activate;
    }

    void GameText::Reset()
    {
    }

    void GameText::Move(Vector3 velocity)
    {
        (void)velocity;
    }
}
