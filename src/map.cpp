/*
** EPITECH PROJECT, 2022
** map.cpp
** File description:
** TODO
*/

#include "map.hpp"

namespace bomberman {
    void Map::drawMap() {
        DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);
        for (float i = 0; i < 32; i++) {
            DrawCube((Vector3){ 0.0f, 0.0f, 15.0f }, i, 2.0f, 1.0f, GRAY);
            DrawCube((Vector3){ -15.0f, 0.0f, 0.0f }, 1.0f, 2.0f, i, GRAY);
            DrawCube((Vector3){ 15.0f, 0.0f, 0.0f }, 1.0, 2.0f, i, GRAY);
            DrawCube((Vector3){ 0.0f, 0.0f, -15.0f }, i, 2.0f, 1.0f, GRAY);
        }
    }
}