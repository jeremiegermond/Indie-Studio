/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** Gamepad
*/

#include "Gamepad.hpp"
#include <cmath>
#include <iostream>

namespace bomberman
{
    Gamepad::Gamepad(int nb)
    {
        id = nb;
    }

    Gamepad::~Gamepad()
    {
    }

    bool Gamepad::IsAvailable() {
        return IsGamepadAvailable(id);
    }

    bool Gamepad::up() {
        if (!IsAvailable())
            return false;
        if (IsGamepadButtonDown(id, GAMEPAD_BUTTON_LEFT_FACE_UP) ||
            (GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y) < -0.10f &&
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y)) >
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X))))))
            return true;
        return false;
    }

    bool Gamepad::down() {
        if (!IsAvailable())
            return false;
        if (IsGamepadButtonDown(id, GAMEPAD_BUTTON_LEFT_FACE_DOWN) ||
            (GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y) > 0.10f &&
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y)) >
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X))))))
            return true;
        return false;
    }

    bool Gamepad::left() {
        if (!IsAvailable())
            return false;
        if (IsGamepadButtonDown(id, GAMEPAD_BUTTON_LEFT_FACE_LEFT) ||
            (GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X) < -0.10f &&
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X)) >
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y))))))
            return true;
        return false;
    }

    bool Gamepad::right() {
        if (!IsAvailable())
            return false;
        if (IsGamepadButtonDown(id, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) ||
            (GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X) > 0.10f &&
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X)) >
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y))))))
            return true;
        return false;
    }

    bool Gamepad::button(int nb) {
        if (!IsAvailable())
            return false;
        return IsGamepadButtonPressed(id, nb);
    };
}
