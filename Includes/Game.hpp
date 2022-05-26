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
#include <vector>
#include "raylib.h"
#include "rlgl.h"
#include "GameObject.hpp"
#include "SceneManager.hpp"

namespace bomberman {

    class Game {
    private:
        int width;
        int height;
        float cam_angle;
        float cam_radius;

        Camera3D camera{};
        Sound sound{};

        SceneManager scenes;
    public:
        Game();
        ~Game();

        void createWindow();
        Scene *createScene();
        Scene *getScene();
        void loadScene(){};

        void run();
    };

}


#endif //BOMBERMAN_GAME_HPP
