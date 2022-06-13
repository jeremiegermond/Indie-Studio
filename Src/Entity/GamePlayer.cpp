/*
** EPITECH PROJECT, 2022
** GamePlayer.cpp
** File description:
** TODO
*/
#include "GamePlayer.hpp"
#include "GameBomb.hpp"

namespace bomberman {
    void GamePlayer::CPUPlay() {
        MyVector3 pos = GetPosition();
        float posX = pos.x;
        float posZ = pos.z;
        int rPosX = int(round(posX));
        int rPosZ = int(round(posZ));

        if (IsKeyPressed(KEY_P))
            printf("%f\n", Vector3Distance(pos, GetPosition(true)));
        if (Vector3Distance(pos, GetPosition(true)) < .01f)
            direction = std::rand() % 4;
        if (direction == 0) {
            if (!map->Collide(int(round(posX + .6)), rPosZ)) {
                Move(MyVector3{speed, 0.0f, 0.0f});
                rotation.z = -1.5;
            }
            else
                direction = std::rand() % 5;
            
        } else if (direction == 1) {
            if (!map->Collide(int(round(posX - .6)), rPosZ)) {
                Move(MyVector3{-speed, 0.0f, 0.0f});
                rotation.z = 1.5;
            }
            else
                direction = std::rand() % 5;
        } else if (direction == 2) {
            if (!map->Collide(rPosX, int(round(posZ + .6)))) {
                Move(MyVector3{0.0f, 0.0f, speed});
                rotation.z = 0;
            }
            else
                direction = std::rand() % 5;
        } else if (direction == 3) {
            if (!map->Collide(rPosX, int(round(posZ - .6)))) {
                Move(MyVector3{0.0f, 0.0f, -speed});
                rotation.z = 3;
            }
            else
                direction = std::rand() % 5;
        } else if (direction == 4) {
            AddBomb();
            direction = std::rand() % 4;
        }
    }

    void GamePlayer::Update() {
        now = std::chrono::system_clock::now();
        AnimatedGameObject::Update();
        if (!canPlay) {
            SetAnimation(1);
            return;
        }
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
        if (!GetActive())
            return;
        elapsed += std::chrono::duration<double, std::milli>(now - previous).count();
        MyVector3 pos = GetPosition();
        float posX = pos.x;
        float posZ = pos.z;
        int rPosX = int(round(posX));
        int rPosZ = int(round(posZ));
        GetPowerUp(map->GetBlock(rPosX, rPosZ));
        map->BreakBlock(rPosX, rPosZ, true);
        if (!cpu && keys) {
            if (IsKeyPressed(keys->bomb())) {
                AddBomb();
            }
            if (IsKeyDown(keys->left())) {
                if (!map->Collide(int(round(posX + .6)), rPosZ))
                    Move(MyVector3{speed, 0.0f, 0.0f});
                rotation.z = -1.5;
            } else if (IsKeyDown(keys->right())) {
                if (!map->Collide(int(round(posX - .6)), rPosZ))
                    Move(MyVector3{-speed, 0.0f, 0.0f});
                rotation.z = 1.5;
            } else if (IsKeyDown(keys->up())) {
                if (!map->Collide(rPosX, int(round(posZ + .6))))
                    Move(MyVector3{0.0f, 0.0f, speed});
                rotation.z = 0;
            } else if (IsKeyDown(keys->down())) {
                if (!map->Collide(rPosX, int(round(posZ - .6))))
                    Move(MyVector3{0.0f, 0.0f, -speed});
                rotation.z = 3;
            } else {
                SetAnimation(1);
            }
        }
        else
            CPUPlay();
        previous = now;
    }


/*

rand / 4 -> if direction = wall rand again



*/

    void GamePlayer::SetPlay(bool play) {
        canPlay = play;
        if (!bombs.empty())
            bombs.clear();
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
        if (lives <= 0)
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

    void GamePlayer::SetActive(bool activate) {
        GameObject::SetActive(activate);
        if (activate)
            lives = 1;
    }

    void GamePlayer::AddBomb() {
        if (maxBombsStat - bombs.size() <= 0)
            return;
        PlaySound(place);
        auto *bomb = new GameBomb(fireUp);
        bomb->SetPosition(GetPosition(true));
        bomb->SetScale(3.5f);
        bombs.push_back(bomb);
    }

    void GamePlayer::GetPowerUp(char block) {
        switch (block) {
            case '5':
                maxBombsStat++;
                break;
            case '6':
                speed += 1.f;
                break;
            case '7':
                lives++;
                break;
            case '8':
                fireUp++;
                break;
            default:
                return;

        }
        PlaySound(levelUp);
    }

    void GamePlayer::Reset() {
        AnimatedGameObject::Reset();
        maxBombsStat = 1;
        lives = 1;
        fireUp = 3;
        speed = 2.f;
    }
}
