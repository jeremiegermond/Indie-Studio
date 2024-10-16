/*
** EPITECH PROJECT, 2022
** GameBomb.cpp
** File description:
** TODO
*/

#include "GameBomb.hpp"

namespace bomberman {
    GameBomb::GameBomb(int fireUp)
            : AnimatedGameObject("../Assets/Level/bomb.iqm",
                                 "../Assets/Level/bomb.png",
                                 "../Assets/Level/bomb.iqm",
                                 0,
                                 .8f), fireUp(fireUp) {
        position = MyVector3{-.5f, 0.0f, -.5f};
        rotation.z = 3.f;
        previous = std::chrono::system_clock::now();
        boom = MySound::loadSound("../Assets/Bomb/boom.mp3");
        MySound::setSoundVolume(boom, 0.5f);
    }

    void GameBomb::Update() {
        now = std::chrono::system_clock::now();
        if (GetActive()) {
            elapsed += std::chrono::duration<double, std::milli>(now - previous).count();
            NextFrame();
            if (!exploded && elapsed >= 4000) {
                exploded = 1;
                explosion = new AnimatedGameObject("../Assets/Level/explosion.iqm", 0, .8f);
                //explosion->SetPosition(position);
                MySound::playSound(boom);
            }
            if (explosion) {
                if (elapsed >= 4650) {
                    SetActive(false);
                    explosion->SetActive(false);
                } else {
                    explosion->Update();
                }
            }
        }
        previous = now;
    }

    int GameBomb::GetExplode() {
        if (exploded == 1) {
            exploded = 2;
            return 1;
        }
        return exploded;
    }

    void GameBomb::Draw() {
        if (!exploded)
            AnimatedGameObject::Draw();
        if (exploded && explosion) {
            for (auto &pos : explosionPos) {
                explosion->SetPosition(pos);
                explosion->Draw();
            }
        }
    }

    int GameBomb::GetFire() const {
        return fireUp;
    }

    void GameBomb::AddExplosion(MyVector3 pos) {
        explosionPos.push_back(pos);
    }
}