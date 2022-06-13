/*
** EPITECH PROJECT, 2022
** game.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_GAME_HPP
#define BOMBERMAN_GAME_HPP

#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "raylib.h"
#include "rlgl.h"
#include "GameObject.hpp"
#include "SceneManager.hpp"
#include "Objects.hpp"

namespace bomberman {
    class Game {
    private:
        int width;
        int height;
        int currentScene;
        SceneManager scenes;
        Image flavicon;
    
    public:
        Game();
        ~Game();
        void createWindow();
        void run();
        void ChangeScene(int i);
        Scene *GetScene();
        SceneManager GetSceneManager();
    };

}


#endif //BOMBERMAN_GAME_HPP
