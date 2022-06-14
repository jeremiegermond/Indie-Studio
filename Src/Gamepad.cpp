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
        if (GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y) < -0.10f &&
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y)) >
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X)))))
            return true;
    }

    bool Gamepad::down() {
        if (!IsAvailable())
            return false;
        if (GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y) > 0.10f &&
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y)) >
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X)))))
            return true;
    }

    bool Gamepad::left() {
        if (!IsAvailable())
            return false;
        if (GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X) < -0.10f &&
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X)) >
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y)))))
            return true;
    }

    bool Gamepad::right() {
        if (!IsAvailable())
            return false;
        if (GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X) > 0.10f &&
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_X)) >
            (fabs(GetGamepadAxisMovement(id, GAMEPAD_AXIS_LEFT_Y)))))
            return true;
    }

    bool Gamepad::button(int nb) {
        if (!IsAvailable())
            return false;
        return IsGamepadButtonPressed(id, nb);
    };
}
