/*
** EPITECH PROJECT, 2022
** GameBomb.cpp
** File description:
** TODO
*/
#include "GameBomb.hpp"

namespace bomberman {
    GameBomb::GameBomb(const std::string &modelPath,
                       const std::string &texturePath,
                       const std::string &animationPath,
                       unsigned int animationCount,
                       float scale)
            : AnimatedGameObject(modelPath, texturePath, animationPath, animationCount, scale) {
        position = MyVector3 {-.5f, 0.0f, -.5f};
        rotation.z = 1.5;
    }

    void GameBomb::Update() {
        NextFrame();
    }
}