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
            if (!map->Collide(int(round(posX + .6)), rPosZ, wallPass)) {
                Move(MyVector3{speed, 0.0f, 0.0f});
                rotation.z = -1.5;
            }
            else
                direction = std::rand() % 5;
            
        } else if (direction == 1) {
            if (!map->Collide(int(round(posX - .6)), rPosZ, wallPass)) {
                Move(MyVector3{-speed, 0.0f, 0.0f});
                rotation.z = 1.5;
            }
            else
                direction = std::rand() % 5;
        } else if (direction == 2) {
            if (!map->Collide(rPosX, int(round(posZ + .6)), wallPass)) {
                Move(MyVector3{0.0f, 0.0f, speed});
                rotation.z = 0;
            }
            else
                direction = std::rand() % 5;
        } else if (direction == 3) {
            if (!map->Collide(rPosX, int(round(posZ - .6)), wallPass)) {
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
        double time = std::chrono::duration_cast<std::chrono::milliseconds>(now - previous).count();
        elapsed += time;
        wallPass -= time;
        wallPass = wallPass > 0 ? wallPass : 0;
        MyVector3 pos = GetPosition();
        float posX = pos.x;
        float posZ = pos.z;
        int rPosX = int(round(posX));
        int rPosZ = int(round(posZ));
        GetPowerUp(map->GetBlock(rPosX, rPosZ));
        map->BreakBlock(rPosX, rPosZ, true, wallPass);
        if (!cpu && keys) {
            if (IsKeyPressed(keys->bomb()) || GetGamepad()->button(7)) {
                AddBomb();
            }
            if (IsKeyDown(keys->left()) || GetGamepad()->left()) {
                if (!map->Collide(int(round(posX + .6)), rPosZ, wallPass))
                    Move(MyVector3{speed, 0.0f, 0.0f});
                rotation.z = -1.5;
            } else if (IsKeyDown(keys->right()) || GetGamepad()->right()) {
                if (!map->Collide(int(round(posX - .6)), rPosZ, wallPass))
                    Move(MyVector3{-speed, 0.0f, 0.0f});
                rotation.z = 1.5;
            } else if (IsKeyDown(keys->up()) || GetGamepad()->up()) {
                if (!map->Collide(rPosX, int(round(posZ + .6)), wallPass))
                    Move(MyVector3{0.0f, 0.0f, speed});
                rotation.z = 0;
            } else if (IsKeyDown(keys->down()) || GetGamepad()->down()) {
                if (!map->Collide(rPosX, int(round(posZ - .6)), wallPass))
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

    void GamePlayer::SetGamepad(Gamepad *gp) {
        gamepad = gp;
    }

    Gamepad *GamePlayer::GetGamepad() {
        return gamepad;
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

    void GamePlayer::SavePlayer(int i) {
        std::ofstream file;
        file.open(TextFormat("player%d.txt", i));
        if (!file.is_open())
            return;
        MyVector3 pos = GetPosition(true);
        file << lives << std::endl;
        file << pos.x << std::endl;
        file << pos.z << std::endl;
        file << GetMaxBombs() << std::endl;
        file << GetSpeed() << std::endl;
        file << wallPass << std::endl;
        file << GetFireUps() << std::endl;
        file.close();
    }

    void GamePlayer::LoadPlayer(int i) {
        std::ifstream file;
        std::string setting;
        MyVector3 newPos = GetPosition(true);
        file.open(TextFormat("player%d.txt", i));
        if (!file.is_open()) {
            return;
        }
        try {
            std::getline(file, setting);
            if (setting.empty())
                return;
            lives = std::stoi(setting);
            std::getline(file, setting);
            if (setting.empty())
                return;
            newPos.x = std::stof(setting);
            std::getline(file, setting);
            if (setting.empty())
                return;
            newPos.z = std::stof(setting);
            SetPosition(newPos);
            std::getline(file, setting);
            if (setting.empty())
                return;
            maxBombsStat = std::stoi(setting);
            std::getline(file, setting);
            if (setting.empty())
                return;
            speed = std::stof(setting);
            std::getline(file, setting);
            if (setting.empty())
                return;
            wallPass = double(std::stoi(setting));
            std::getline(file, setting);
            if (setting.empty())
                return;
            fireUp = std::stoi(setting);
        } catch (...) {}
        if (lives <= 0)
            SetActive(false);
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
                if (maxBombsStat < 6)
                    maxBombsStat++;
                break;
            case '6':
                if (speed < 6)
                    speed += 1.f;
                break;
            case '7':
                wallPass = 10000;
                break;
            case '8':
                if (fireUp < 8)
                    fireUp++;
                break;
            default:
                return;

        }
        PlaySound(levelUp);
    }

    int GamePlayer::GetMaxBombs() const {
        return maxBombsStat;
    }

    float GamePlayer::GetSpeed() const {
        return speed;
    }

    int GamePlayer::GetFireUps() const {
        return fireUp;
    }

    float GamePlayer::GetWall() const {
        return wallPass ? wallPass / 1000.f : 0.f;
    }

    void GamePlayer::Reset() {
        AnimatedGameObject::Reset();
        maxBombsStat = 1;
        lives = 1;
        fireUp = 3;
        speed = 2.f;
        wallPass = 0;
        keys = nullptr;
        gamepad = nullptr;
        cpu = true;
    }
}
