/*
** EPITECH PROJECT, 2022
** GameScript.cpp
** File description:
** GameScript
*/

#include "GameScript.hpp"
#include "Game.hpp"

namespace bomberman {
    GameScript::GameScript(Game *game,
                           int script) {
        currentScript = script;
        _game = game;
        active = true;
        positions.emplace_back(-.47f, 0.0f, -.79f);
        positions.emplace_back(-.44f, 0.0f, -.54f);
        positions.emplace_back(-.65f, 0.0f, -.1f);
        positions.emplace_back(-.88f, 0.0f, -.06f);
        positions.emplace_back(8.0f, 0.0f, -8.0f);
        positions.emplace_back(-8.0f, 0.0f, -8.0f);
        positions.emplace_back(-8.0f, 0.0f, 8.0f);
        positions.emplace_back(8.0f, 0.0f, 8.0f);
        rotations.emplace_back(.0f, .0f, 1.5f);
        rotations.emplace_back(.0f, .0f, 1.5f);
        rotations.emplace_back(.0f, .0f, 3.0f);
        rotations.emplace_back(.0f, .0f, 3.0f);
    }

    void GameScript::Update() {
        if (!active)
            return;
        switch (currentScript) {
            case 1:
                PressToZoom();
                break;
            case 2:
                PressToPlay();
                break;
            case 3:
                UpdateBomb();
                break;
            default:
                break;
        }
    }

    void GameScript::SetActive(bool activate) {
        active = activate;
    }

    void GameScript::Reset() {
        SetActive(true);
    }

    void GameScript::PressToZoom() {
        if (IsKeyPressed(KEY_ENTER)) {
            std::vector<GamePlayer *> players;
            for (int i = 0; i < 4; i++) {
                players.push_back(_game->GetScene()->PopPlayer());
                players.back()->SetPosition(positions[i]);
                players.back()->SetRotation(rotations[i]);
            }
            _game->GetScene()->Populate(players);
            _game->GetScene()->GetCamera(0)->SetMode(CAMERA_CUSTOM);
            _game->GetScene()->NextCamera();
            _game->GetScene()->GetText(0)->SetActive(false);
            _game->GetScene()->GetText(1)->SetActive(false);
            _game->GetScene()->GetText(2)->SetActive(true);
            auto buttons = _game->GetScene()->GetButtons();
            for (auto button: buttons) {
                if (button->GetType() == BUTTON_SELECT || button->GetType() == BUTTON_AI) {
                    button->SetActive(true);
                }
            }
            currentScript = 2;
        }
    }

    void GameScript::PressToPlay() {
        auto buttons = _game->GetScene()->GetButtons();
        int i = 0;
        for (auto button: buttons) {
            if (button->GetType() == BUTTON_SELECT) {
                if (button->GetState()) {
                    _game->GetScene()->ChangePlayer(i);
                    _game->GetScene()->GetPlayer(i)->SetPosition(positions[i]);
                    _game->GetScene()->GetPlayer(i)->SetRotation(rotations[i]);
                    button->SetState(false);
                }
                i++;
            }
        }
        if (IsKeyPressed(KEY_ENTER)) {
            std::vector<GamePlayer *> players;
            int cpuselect = 0;
            for (auto button: buttons)
                if (button->GetType() == BUTTON_AI) {
                    if (button->GetState())
                        _game->GetScene()->GetPlayer(cpuselect)->setCpu(false);
                    cpuselect++;
                }
            for (int x = 0; x < 4; x++) {
                auto player = _game->GetScene()->GetPlayer(x);
                player->SetScale(.4f);
                player->SetPosition(positions[4+x]);
                player->SetPlay(true);
                if (!player->is_cpu())
                    player->SetKeys(x);
                players.push_back(player);
            }
            _game->ChangeScene(1);
            _game->GetScene()->Populate(players);
        }
    }

    void GameScript::UpdateBomb() {
        std::vector<GameBomb *> bombs;
        std::vector<GamePlayer *> players;
        std::vector<MyVector3> cases;
        std::vector<MyVector3> playersPos;
        for (int x = 0; x < 4; x++) {
            auto player = _game->GetScene()->GetPlayer(x);
            if (player == nullptr)
                break;
            players.push_back(player);
            playersPos.push_back(player->GetPosition(true));
            for (auto bomb: player->GetBombs())
                bombs.push_back(bomb);
        }
        GameDrawMap *map = _game->GetScene()->GetMap();
        for (auto bomb: bombs) {
            if (!bomb->GetActive())
                continue;
            int exploded = bomb->GetExplode();
            if (exploded == 0)
                continue;
            MyVector3 pos = bomb->GetPosition(true);
            MyVector3 tmpP = pos;
            int fire = bomb->GetFire();
            cases.push_back(pos);
            int x = int(pos.x);
            bool posX = false;
            bool negX = false;
            bool posZ = false;
            bool negZ = false;
            int z = int(pos.z);
            for (int i = 1; i < fire; i++) {
                if (!posX) {
                    tmpP.x = pos.x + float(i);
                    if (map->GetBlock(x + i, z) != '0') {
                        if (exploded == 1)
                            map->BreakBlock(x + i, z);
                        posX = true;
                    }
                    cases.push_back(tmpP);
                }
                if (!negX) {
                    tmpP.x = pos.x - float(i);
                    if (map->GetBlock(x - i, z) != '0') {
                        if (exploded == 1)
                            map->BreakBlock(x - i, z);
                        negX = true;
                    }
                    cases.push_back(tmpP);
                }
                tmpP.x = pos.x;
                if (!posZ) {
                    tmpP.z = pos.z + float(i);
                    if (map->GetBlock(x, z + i) != '0') {
                        if (exploded == 1)
                            map->BreakBlock(x, z + i);
                        posZ = true;
                    }
                    cases.push_back(tmpP);
                }
                if (!negZ) {
                    tmpP.z = pos.z - float(i);
                    if (map->GetBlock(x, z - i) != '0') {
                        if (exploded == 1)
                            map->BreakBlock(x, z - i);
                        negZ = true;
                    }
                    cases.push_back(tmpP);
                }
            }
            for (auto collide: cases) {
                for (int i = 0; i < 4; i++) {
                    if (players[i] == nullptr)
                        break;

                    // printf("c: %f %f\n", collide.x, collide.z);
                    // printf("p: %f %f\n", playersPos[i].x, playersPos[i].z);
                    if (Vector3Distance(playersPos[i], collide) < .5f) {
                        // printf("%f\n", Vector3Distance(playersPos[i], collide));
                        players[i]->RemoveLive();
                    }
                }
            }
        }
    }
}
