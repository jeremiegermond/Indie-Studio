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

        SceneManager scenes;
    public:
        Game();

        ~Game();

        void createWindow();

        void run();
    };

}


#endif //BOMBERMAN_GAME_HPP
