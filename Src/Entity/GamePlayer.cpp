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
        if (IsKeyDown(KEY_P))
            printf("Ppos: %f %f %f\n", position.x, position.y, position.z);
        if (IsKeyPressed(KEY_SPACE)) {
            auto *bomb = new GameBomb(fireUp);
            bomb->SetPosition(GetPosition(true));
            bomb->SetScale(3.5f);
            bombs.push_back(bomb);
        }
        if (IsKeyDown(KEY_A)) {
            Move(MyVector3{1.0f, 0.0f, 0.0f});
            rotation.z = -1.5;
        } else if (IsKeyDown(KEY_D)) {
            Move(MyVector3{-1.0f, 0.0f, 0.0f});
            rotation.z = 1.5;
        } else if (IsKeyDown(KEY_W)) {
            Move(MyVector3{0.0f, 0.0f, 1.0f});
            rotation.z = 0;
        } else if (IsKeyDown(KEY_S)) {
            Move(MyVector3{0.0f, 0.0f, -1.0f});
            rotation.z = 3;
        } else {
            SetAnimation(1);
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
        previous = now;
    }

    void GamePlayer::SetPlay(bool play) {
        canPlay = play;
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
}
