/*
** EPITECH PROJECT, 2022
** GamePlayer.cpp
** File description:
** TODO
*/
#include "GamePlayer.hpp"

namespace bomberman {
    GamePlayer::GamePlayer(const std::string &modelPath,
                           const std::string &texturePath,
                           const std::string &animationPath,
                           unsigned int animationCount)
            : AnimatedGameObject(modelPath, texturePath, animationPath, animationCount) {

    }

    void GamePlayer::Update() {
        AnimatedGameObject::Update();
    }
}
