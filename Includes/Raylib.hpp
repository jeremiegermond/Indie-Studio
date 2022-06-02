/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** Raylib
*/

#pragma once

#include <iostream>
#include "raylib.h"

namespace bomberman {
    class Raylib {
    private:
        int width;
        int height;
        const std::string title;

    public:
        Raylib(const int &width, const int &, const std::string &title);
        ~Raylib();
    };

}