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
#include "Map.hpp"
#include "GameObject.hpp"
#include "Scene.hpp"

namespace bomberman {

    class Game {
    private:
        int width;
        int height;
        float cam_angle;
        float cam_radius;

        Camera3D camera;
        Sound sound;

        std::vector<Scene *> scenes;

        Map map;
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
