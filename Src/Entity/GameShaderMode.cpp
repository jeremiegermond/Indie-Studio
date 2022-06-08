/*
** EPITECH PROJECT, 2022
** GameShaderMode.cpp
** File description:
** GameShaderMode
*/

#include "GameShaderMode.hpp"

namespace bomberman {
    GameShaderMode::GameShaderMode(const std::string &darkmode, const std::string &lightmode, float x, float y, MyColor color) {
        _imageLightmode = LoadImage(lightmode.c_str());
        _imageDarkmode = LoadImage(darkmode.c_str());
        _textureLightmode = LoadTextureFromImage(_imageLightmode);
        _textureDarkmode =LoadTextureFromImage(_imageDarkmode);
        _position.x = x;
        _position.y = y;
        _color = color;
        UnloadImage(_imageLightmode);
        UnloadImage(_imageDarkmode);
    }

    void GameShaderMode::Draw() {
        // Vector2 mousePoint = { 0.0f, 0.0f };
        Vector2 mouse = GetMousePosition();
        Rectangle button = { _position.x, _position.y, float (_imageDarkmode.width), float (_imageDarkmode.height) };
        if (darkmode) {
            DrawTexture(_textureDarkmode, int (_position.x), int (_position.y), _color);
            if (CheckCollisionPointRec(mouse, button)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    darkmode = false;
            }
        } else {
            DrawTexture(_textureLightmode, int (_position.x - 50), int (_position.y - 25), _color);
            if (CheckCollisionPointRec(mouse, button)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    darkmode = true;
            }
        }
    }

    void GameShaderMode::SetActive(bool activate) {
        active = activate;
    }
}

