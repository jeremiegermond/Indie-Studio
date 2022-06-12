/*
** EPITECH PROJECT, 2022
** GamePlayer.cpp
** File description:
** TODO
*/
#include "GamePlayer.hpp"
#include "GameBomb.hpp"

namespace bomberman {
    void GamePlayer::Update() {
        now = std::chrono::system_clock::now();
        AnimatedGameObject::Update();
        if (!canPlay) {
            SetAnimation(1);
            return;
        }
        elapsed += std::chrono::duration<double, std::milli>(now - previous).count();
        if (!cpu) {
            if (IsKeyPressed(keys->bomb()) && maxBombsStat - bombs.size() > 0) {
                auto *bomb = new GameBomb(fireUp);
                bomb->SetPosition(GetPosition(true));
                bomb->SetScale(3.5f);
                bombs.push_back(bomb);
            }
            MyVector3 pos = GetPosition();
            float posX = pos.x;
            float posZ = pos.z;
            if (IsKeyDown(keys->left()) && map->GetBlock(int(round(posX + .6)), int(round(posZ))) == '0') {
                Move(MyVector3{1.0f, 0.0f, 0.0f});
                rotation.z = -1.5;
            } else if (IsKeyDown(keys->right()) &&
                       map->GetBlock(int(round(posX - .6)), int(round(posZ))) == '0') {
                Move(MyVector3{-1.0f, 0.0f, 0.0f});
                rotation.z = 1.5;
            } else if (IsKeyDown(keys->up()) &&
                       map->GetBlock(int(round(posX)), int(round(posZ + .6))) == '0') {
                Move(MyVector3{0.0f, 0.0f, 1.0f});
                rotation.z = 0;
            } else if (IsKeyDown(keys->down()) &&
                       map->GetBlock(int(round(posX)), int(round(posZ - .6))) == '0') {
                Move(MyVector3{0.0f, 0.0f, -1.0f});
                rotation.z = 3;
            } else {
                SetAnimation(1);
            }
        }
        else;//  set ai input
        for (auto bomb : bombs) {
            bomb->Update();
            bomb->Draw();
        }
        size_t size = bombs.size();
        for (size_t i = 0; i < size; i++) {
            if (!bombs[i]->GetActive()) {
                bombs.erase(bombs.begin());
                i--;
                size--;
            }
        }
        previous = now;
    }

    void GamePlayer::SetPlay(bool play) {
        canPlay = play;
    }

    void GamePlayer::SetKeys(KeysLayout playerNB) {
        keys = new Keyboard(playerNB);
    }

    void GamePlayer::SetKeys(int playerNB) {
        keys = new Keyboard(playerNB);
    }

    std::vector<GameBomb *> GamePlayer::GetBombs() {
        return bombs;
    }

    void GamePlayer::RemoveLive() {
        if (elapsed < 800)
            return;
        elapsed = .0f;
        lives--;
        std::cout << lives << std::endl;
    }

    bool GamePlayer::is_cpu() {
        return cpu;
    }

    void GamePlayer::switchPlayer() {
        cpu = !cpu;
    }

    void GamePlayer::setCpu(bool nv) {
        cpu = nv;
    }

    void GamePlayer::SetMap(GameDrawMap *newMap) {
        map = newMap;
    }
}
