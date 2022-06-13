/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** Gamepad
*/

#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include "raylib.h"

namespace bomberman {
    class Gamepad {
        private:
            int id{};
        public:
            Gamepad(int nb);
            ~Gamepad();
            bool IsAvailable();
            bool up();
            bool down();
            bool left();
            bool right();
            bool button(int nb);
    };
}

#endif /* !GAMEPAD_HPP_ */
