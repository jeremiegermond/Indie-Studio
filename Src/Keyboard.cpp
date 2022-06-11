/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** Keyboard
*/

#include "Keyboard.hpp"

namespace bomberman {
    Keyboard::Keyboard(KeysLayout playernb) {
        std::vector<KeyboardKey> keys = layouts[(int)playernb];
        up_key = keys.at(0);
        down_key = keys.at(2);
        left_key = keys.at(1);
        right_key = keys.at(3);
        bomb_key = keys.at(4);
    };

    Keyboard::Keyboard(int playernb) {
        std::vector<KeyboardKey> keys = layouts[playernb];
        up_key = keys.at(0);
        down_key = keys.at(2);
        left_key = keys.at(1);
        right_key = keys.at(3);
        bomb_key = keys.at(4);
    };

    Keyboard::~Keyboard()
    {
    }

    KeyboardKey Keyboard::up() {
        return up_key;
    };
    KeyboardKey Keyboard::down() {
        return down_key;
    };
    KeyboardKey Keyboard::left() {
        return left_key;
    };
    KeyboardKey Keyboard::right() {
        return right_key;
    };
    KeyboardKey Keyboard::bomb() {
        return bomb_key;
    };
}