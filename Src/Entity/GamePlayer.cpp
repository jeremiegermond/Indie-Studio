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
        MyVector3 rPos = GetPosition(true);
        bool dir[4] = {};
        for (auto bomb: bombs) {
            auto bRPos = bomb->GetPosition(true);
            dir[0] += fabs(rPos.x + 1.f - bRPos.x) < .1f;
            dir[1] += fabs(rPos.x - 1.f - bRPos.x) < .1f;
            dir[2] += fabs(rPos.z + 1.f - bRPos.z) < .1f;
            dir[3] += fabs(rPos.z - 1.f - bRPos.z) < .1f;
            dir[0] += fabs(rPos.z - bRPos.z) < .1f && (bRPos.x - rPos.x) > .0f;
            dir[1] += fabs(rPos.z - bRPos.z) < .1f && (bRPos.x - rPos.x) < .0f;
            dir[2] += fabs(rPos.x - bRPos.x) < .1f && (bRPos.z - rPos.z) > .0f;
            dir[3] += fabs(rPos.x - bRPos.x) < .1f && (bRPos.z - rPos.z) < .0f;
            dir[0] += Collide(round(pos.x + .6f), rPos.z);
            dir[1] += Collide(round(pos.x - .6f), rPos.z);
            dir[2] += Collide(rPos.x, round(pos.z + .6f));
            dir[3] += Collide(rPos.x, round(pos.z -  .6f));
        }
        if (decision > 500) {
            direction = GetRandomValue(0, 5);
            decision = 0;
        }
        int decisions = 4;
        for (bool i : dir) {
            decisions -= i;
        }
        if (direction != 4 && decisions == 1) {
            for (int i = 0; i < 4; i++)
                if (!dir[i])
                    direction = i;
        }

        if (direction == 0 && !dir[0]) {
            MoveTo(round(pos.x + .6f), rPos.z);
            rotation.z = -1.5;
        } else if (direction == 1 && !dir[1]) {
            MoveTo(round(pos.x - .6f), rPos.z);
            rotation.z = 1.5;
        } else if (direction == 2 && !dir[2]) {
            MoveTo(rPos.x, round(pos.z + .6f));
            rotation.z = 0;
        } else if (direction == 3 && !dir[3]) {
            MoveTo(rPos.x, round(pos.z - .6f));
            rotation.z = 3;
        } else if (direction == 4 && elapsed > 5000.) {
            if (IsBreakable(round(pos.x + .6f), rPos.z) ||
                IsBreakable(round(pos.x - .6f), rPos.z) ||
                IsBreakable(rPos.x, round(pos.z + .6f)) ||
                IsBreakable(rPos.x, round(pos.z - .6f)))
                AddBomb();
            else if (!map->GetBreakTiles())
                AddBomb();
            direction = GetRandomValue(0, 4);
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
        double time = double(std::chrono::duration_cast<std::chrono::milliseconds>(now - previous).count());
        elapsed += time;
        decision += time;
        wallPass -= time;
        wallPass = wallPass > 0 ? wallPass : 0;
        UpdateMovement();
        if (!cpu && keys)
            PlayPlayer();
        else
            CPUPlay();
        previous = now;
    }

    void GamePlayer::SetPlay(bool play) {
        elapsed = .0f;
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
        if (!MySound::isSoundPlaying(step))
            MySound::playSound(step);
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
        MyVector3 rPos = GetPosition(true);
        if (IsBreakable(rPos.x, rPos.z))
            return;
        if (maxBombsStat - bombs.size() <= 0)
            return;
        MySound::playSound(place);
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
        MySound::playSound(levelUp);
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
        fireUp = FIRE_UP;
        speed = 2.f;
        wallPass = 0;
        elapsed = .0f;
        keys = nullptr;
        gamepad = nullptr;
        cpu = true;
        intention.x = position.x;
        intention.y = position.z;
    }

    void GamePlayer::SetPosition(MyVector3 position) {
        GameObject::SetPosition(position);
        intention.x = position.x;
        intention.y = position.z;
    }

    void GamePlayer::MoveTo(float x,
                            float z) {
        int newX = int(x);
        int newZ = int(z);
        if (!Collide(x, z)) {
            intention.x = float(newX);
            intention.y = float(newZ);
        } else {
            direction = GetRandomValue(0, 4);
        }
    }

    void GamePlayer::Move(MyVector2 velocity) {
        MyVector3 newVelocity = {velocity.x, .0f, velocity.y};
        AnimatedGameObject::Move(newVelocity);
    }

    void GamePlayer::PlayPlayer() {
        MyVector3 pos = GetPosition();
        MyVector3 rPos = GetPosition(true);
        if (MyGamepad::isKeyPressed(keys->bomb()) || GetGamepad()->button(7)) {
            AddBomb();
        }
        if (MyGamepad::isKeyDown(keys->left()) || GetGamepad()->left()) {
            MoveTo(round(pos.x + .6f), rPos.z);
            rotation.z = -1.5;
        } else if (MyGamepad::isKeyDown(keys->right()) || GetGamepad()->right()) {
            MoveTo(round(pos.x - .6f), rPos.z);
            rotation.z = 1.5;
        } else if (MyGamepad::isKeyDown(keys->up()) || GetGamepad()->up()) {
            MoveTo(rPos.x, round(pos.z + .6f));
            rotation.z = 0;
        } else if (MyGamepad::isKeyDown(keys->down()) || GetGamepad()->down()) {
            MoveTo(rPos.x, round(pos.z - .6f));
            rotation.z = 3;
        }
    }

    void GamePlayer::UpdateMovement() {
        MyVector3 pos = GetPosition();
        MyVector3 rPos = GetPosition(true);
        int rPosX = int(rPos.x);
        int rPosZ = int(rPos.z);
        bool moveX = fabs(pos.x - intention.x) > .1f;
        bool moveZ = fabs(pos.z - intention.y) > .1f;
        GetPowerUp(map->GetBlock(rPosX, rPosZ));
        map->BreakBlock(rPosX, rPosZ, true, wallPass);
        if (moveX) {
            Move(MyVector2{speed * (pos.x - intention.x > 0 ? -1.f : 1.f), .0f});
        }
        if (moveZ) {
            Move(MyVector2{.0f, speed * (pos.z - intention.y > 0 ? -1.f : 1.f)});
        }
        if (!moveX && !moveZ) {
            SetAnimation(1);
        }
    }

    bool GamePlayer::IsBreakable(float x,
                                 float z) {
        int newX = int(x);
        int newZ = int(z);
        if (map->GetBlock(newX, newZ) == '2') {
            return true;
        }
        return false;
    }

    bool GamePlayer::Collide(float x,
                             float z) {
        int newX = int(x);
        int newZ = int(z);
        return map->Collide(newX, newZ, wallPass);
    }
}
