/*
** EPITECH PROJECT, 2022
** game.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_GAME_HPP
#define BOMBERMAN_GAME_HPP

#include <iostream>
#include <cmath>
#include "raylib.h"
#include "Map.hpp"

namespace bomberman {

    class Game {
    private:
        int width;
        int height;
        unsigned int count;
        float cam_angle;
        float cam_radius;
        int animFrameCounter;

        Camera3D camera;

        Model model;
        Texture2D texture;
        ModelAnimation *animation;
        Sound sound;

        Map map;
    public:
        Game();
        ~Game();

        void loadObjects();
        void run();
    };

}


#endif //BOMBERMAN_GAME_HPP
