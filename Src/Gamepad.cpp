/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** Gamepad
*/

#include "Gamepad.hpp"
#include "MyGamepad.hpp"
#include <cmath>
#include <iostream>

namespace bomberman
{
    Gamepad::Gamepad(int nb) : id(nb) {}

    bool Gamepad::IsAvailable() {
        return MyGamepad::isGamepadAvailable(id);
    }

    bool Gamepad::up() {
        if (!IsAvailable())
            return false;
        if (MyGamepad::isGamepadButtonDown(id, GAMEPAD_BUTTON_LEFT_FACE_UP) ||
            (MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y) < -0.10f &&
            (fabs(MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y)) >
            (fabs(MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X))))))
            return true;
        return false;
    }

    bool Gamepad::down() {
        if (!IsAvailable())
            return false;
        if (MyGamepad::isGamepadButtonDown(id, GAMEPAD_BUTTON_LEFT_FACE_DOWN) ||
            (MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y) > 0.10f &&
            (fabs(MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y)) >
            (fabs(MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X))))))
            return true;
        return false;
    }

    bool Gamepad::left() {
        if (!IsAvailable())
            return false;
        if (MyGamepad::isGamepadButtonDown(id, GAMEPAD_BUTTON_LEFT_FACE_LEFT) ||
            (MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X) < -0.10f &&
            (fabs(MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X)) >
            (fabs(MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y))))))
            return true;
        return false;
    }

    bool Gamepad::right() {
        if (!IsAvailable())
            return false;
        if (MyGamepad::isGamepadButtonDown(id, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) ||
            (MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X) > 0.10f &&
            (fabs(MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X)) >
            (fabs(MyGamepad::getGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y))))))
            return true;
        return false;
    }

    bool Gamepad::button(int nb) {
        if (!IsAvailable())
            return false;
        return MyGamepad::isGamepadButtonPressed(id, nb);
    };
}
