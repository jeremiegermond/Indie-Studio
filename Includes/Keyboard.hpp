/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** Keyboard
*/

#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include "raylib.h"
#include <map>
#include <vector>
#include <string>

namespace bomberman {
    enum class KeysLayout {
        P1 = 0,
        P2,
        P3,
        P4
    };

    class Keyboard {
        private:
            KeyboardKey up_key;
            KeyboardKey down_key;
            KeyboardKey left_key;
            KeyboardKey right_key;
            KeyboardKey bomb_key;
            std::vector<std::vector<KeyboardKey>> layouts = {
                {KEY_W, KEY_A, KEY_S, KEY_D, KEY_SPACE},
                {KEY_UP, KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEY_RIGHT_CONTROL},
                {KEY_O, KEY_K, KEY_L, KEY_M, KEY_P},
                {KEY_KP_8, KEY_KP_4, KEY_KP_5, KEY_KP_6, KEY_KP_ADD},
            };
        public:
            Keyboard(KeysLayout playernb);
            Keyboard(int playernb);
            ~Keyboard();
            KeyboardKey up();
            KeyboardKey down();
            KeyboardKey left();
            KeyboardKey right();
            KeyboardKey bomb();
    };
}
#endif /* !KEYBOARD_HPP_ */
