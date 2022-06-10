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
        rotation.z = 3.f;
        explode = std::chrono::system_clock::now() + std::chrono::seconds(5);
        end_life = std::chrono::system_clock::now() + std::chrono::seconds(6);
        boom = LoadSound("../Assets/Bomb/boom.mp3");
        SetSoundVolume(boom, 0.5f);
    }

    void GameBomb::Update() {
        NextFrame();
        tPoint now = std::chrono::system_clock::now();
        if (!exploded && now >= explode) {
            exploded = true;
            explode = std::chrono::system_clock::now() + std::chrono::seconds(10);
            explosion = new AnimatedGameObject("../Assets/Level/explosion.iqm", 0);
            explosion->SetPosition(position);
            PlaySound(boom);
        }
        if (explosion && now >= end_life) {
            SetActive(false);
            explosion->SetActive(false);
        } else if (exploded && explosion) {
            explosion->Update();
        }
    }

    bool GameBomb::GetExplode() const {
        return exploded;
    }

    void GameBomb::Draw() {
        AnimatedGameObject::Draw();
        if (exploded && explosion)
            explosion->Draw();
    }
}