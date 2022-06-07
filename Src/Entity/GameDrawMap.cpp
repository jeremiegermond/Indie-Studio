/*
** EPITECH PROJECT, 2022
** GameDrawMap.cpp
** File description:
** GameDrawMap
*/

#include "GameDrawMap.hpp"

namespace bomberman {

    GameDrawMap::GameDrawMap(MyVector3 cubePosition, MyColor color) {
        _cubePosition = cubePosition;
        _color = color;
    }

    void GameDrawMap::Draw() {
        DrawCube(_cubePosition, 1.0f, 1.0f, 1.0f, _color);
    }

    void GameDrawMap::SetActive(bool activate) {
        active = activate;
    }
}   
