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
        if (!GetActive())
            return;
        elapsed += std::chrono::duration<double, std::milli>(now - previous).count();
        if (!cpu) {
            if (IsKeyPressed(keys->bomb()) && maxBombsStat - bombs.size() > 0) {
                PlaySound(place);
                auto *bomb = new GameBomb(fireUp);
                bomb->SetPosition(GetPosition(true));
                bomb->SetScale(3.5f);
                bombs.push_back(bomb);
            }
            
            
            MyVector3 pos = GetPosition();
            float posX = pos.x;
            float posZ = pos.z;
            float speed = 2.f;
            if (IsKeyDown(keys->left())) {
                if (map->GetBlock(int(round(posX + .6)), int(round(posZ))) == '0')
                    Move(MyVector3{speed, 0.0f, 0.0f});
                rotation.z = -1.5;
            } else if (IsKeyDown(keys->right())) {
                if (map->GetBlock(int(round(posX - .6)), int(round(posZ))) == '0')
                    Move(MyVector3{-speed, 0.0f, 0.0f});
                rotation.z = 1.5;
            } else if (IsKeyDown(keys->up())) {
                if (map->GetBlock(int(round(posX)), int(round(posZ + .6))) == '0')
                    Move(MyVector3{0.0f, 0.0f, speed});
                rotation.z = 0;
            } else if (IsKeyDown(keys->down())) {
                if (map->GetBlock(int(round(posX)), int(round(posZ - .6))) == '0')
                    Move(MyVector3{0.0f, 0.0f, -speed});
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
        if (!bombs.empty())
            bombs.erase(bombs.begin());
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
        PlaySound(dead);
        SetActive(false);
    }

    bool GamePlayer::isCpu() {
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

    void GamePlayer::Move(MyVector3 velocity) {
        AnimatedGameObject::Move(velocity);
        if (!IsSoundPlaying(step))
            PlaySound(step);
    }

    void GamePlayer::SavePlayer() {

    }

    void GamePlayer::LoadPlayer() {

    }
}
