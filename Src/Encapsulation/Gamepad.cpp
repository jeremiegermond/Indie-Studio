/*
** EPITECH PROJECT, 2022
** Gamepad.cpp
** File description:
** TODO
*/

#include "MyGamepad.hpp"

namespace bomberman {
    bool MyGamepad::isKeyPressed(int key) {
        return IsKeyPressed(key);
    }

    bool MyGamepad::isGamepadAvailable(int gamepad) {
        return IsGamepadAvailable(gamepad);
    }

    bool MyGamepad::isGamepadButtonDown(int gamepad, int button) {
        return IsGamepadButtonDown(gamepad, button);
    }

    float MyGamepad::getGamepadAxisMovement(int gamepad, int axis) {
        return GetGamepadAxisMovement(gamepad, axis);
    }

    bool MyGamepad::isGamepadButtonPressed(int gamepad, int button) {
        return IsGamepadButtonPressed(gamepad, button);
    }
}