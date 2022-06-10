/*
** EPITECH PROJECT, 2022
** GamePlayer.cpp
** File description:
** TODO
*/
#include "GamePlayer.hpp"
#include "Game.hpp"

namespace bomberman {
    GamePlayer::GamePlayer(const std::string &modelPath,
                           const std::string &texturePath,
                           const std::string &animationPath,
                           Game *game,
                           unsigned int animationCount,
                           float scale)
            : AnimatedGameObject(modelPath, texturePath, animationPath, animationCount, scale) {
        pGame = game;
    }

    void GamePlayer::Update() {
        AnimatedGameObject::Update();
        if (IsKeyPressed(KEY_SPACE)) {
            auto *bomb = new GameBomb("../Assets/Level/bomb.iqm", "../Assets/Level/bomb.png");
            bomb->SetPosition(position);
            bomb->SetScale(3.5f);
            pGame->GetScene()->AddEntity(bomb);
        }
    }
}
