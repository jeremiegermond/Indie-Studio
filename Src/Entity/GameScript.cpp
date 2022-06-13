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
        positions.emplace_back(8.0f, 0.0f, 8.0f);
        positions.emplace_back(8.0f, 0.0f, -8.0f);
        positions.emplace_back(-8.0f, 0.0f, 8.0f);
        positions.emplace_back(-8.0f, 0.0f, -8.0f);
        rotations.emplace_back(.0f, .0f, 1.5f);
        rotations.emplace_back(.0f, .0f, 1.5f);
        rotations.emplace_back(.0f, .0f, 3.0f);
        rotations.emplace_back(.0f, .0f, 3.0f);
        click = LoadSound("../Assets/Bomb/click.mp3");
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
                SelectLoad();
                break;
            case 4:
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
            PlaySound(click);
            _game->GetScene()->GetCamera(0)->SetMode(CAMERA_CUSTOM);
            _game->GetScene()->NextCamera();
            LoadPlayers();
            ActivateSelection();
            currentScript = 2;
        }
    }

    void GameScript::PressToPlay() {
        auto scene = _game->GetScene();
        auto buttons = scene->GetButtons();
        int i = 0;
        for (auto button: buttons) {
            if (button->GetType() == BUTTON_SELECT) {
                if (button->GetState()) {
                    scene->ChangePlayer(i);
                    scene->GetPlayer(i)->SetPosition(positions[i]);
                    scene->GetPlayer(i)->SetRotation(rotations[i]);
                    button->SetState(false);
                }
                i++;
            }
        }
        if (IsKeyPressed(KEY_ENTER)) {
            PlaySound(click);
            currentScript = 3;
            int cpuselect = 0;
            _game->GetScene()->GetText(2)->SetActive(false);
            for (auto button: buttons) {
                if (button->GetType() == BUTTON_AI) {
                    if (button->GetState())
                        scene->GetPlayer(cpuselect)->setCpu(false);
                    cpuselect++;
                    button->SetActive(false);
                }
            }
            scene->SetActiveButton(BUTTON_SELECT, false, true);
            scene->SetActiveButton(BUTTON_AI, false);
            scene->SetActiveButton(BUTTON_LOAD, true, true);
        }
    }


    void GameScript::SelectLoad() {
        auto scene = _game->GetScene();
        auto buttons = scene->GetButtons();
        std::vector<GamePlayer *> players;
        int i = 0;
        for (auto button: buttons) {
            if (button->GetType() == BUTTON_LOAD) {
                if (button->GetState()) {
                    button->SetState(false);
                    for (int x = 0; x < 4; x++) {
                        auto player = scene->GetPlayer(x);
                        player->SetScale(.4f);
                        player->SetPosition(positions[4+x]);
                        player->SetPlay(true);
                        if (!player->isCpu())
                            player->SetKeys(x);
                        players.push_back(player);
                    }
                    scene->SetActiveButton(BUTTON_MENU, false, true);
                    _game->ChangeScene(1);
                    scene = _game->GetScene();
                    auto map = scene->GetMap();
                    scene->Populate(players);
                    if (map && i) {
                        map->LoadMap();
                    } else if (map) {
                        map->GenerateMap();
                    }
                }
                i++;
            }
        }
    }

    void GameScript::UpdateBomb() {
        std::vector<GameBomb *> bombs;
        std::vector<GamePlayer *> players;
        std::vector<MyVector3> cases;
        std::vector<MyVector3> playersPos;
        auto scene = _game->GetScene();
        auto map = scene->GetMap();
        auto btnReturn = scene->GetButton(0);
        if (btnReturn && btnReturn->GetState()) {
            btnReturn->SetState(false);
            map->Save();
            _game->ChangeScene(0);
            scene = _game->GetScene();
            auto *script = scene->GetScript(0);
            script->currentScript = 2;
            script->ActivateSelection();
            script->LoadPlayers(true);
            return;
        }
        for (int x = 0; x < 4; x++) {
            auto player = scene->GetPlayer(x);
            if (player == nullptr)
                break;
            players.push_back(player);
            if (!player->GetActive())
                scene->GetImage(x)->SetColor(GRAY);
            playersPos.push_back(player->GetPosition());
            map->GetBlock(int (round(playersPos.back().x)), int(round(playersPos.back().z)));
            for (auto bomb: player->GetBombs())
                bombs.push_back(bomb);
        }
        for (auto bomb: bombs) {
            if (!bomb->GetActive())
                continue;
            int exploded = bomb->GetExplode();
            if (exploded != 1)
                continue;
            MyVector3 pos = bomb->GetPosition(true);
            MyVector3 tmpP = pos;
            int fire = bomb->GetFire();
            cases.push_back(pos);
            int x = int(pos.x);
            int z = int(pos.z);
            bool posX = false;
            bool negX = false;
            bool posZ = false;
            bool negZ = false;
            for (int i = 1; i <= fire; i++) {
                if (!posX) {
                    tmpP.x = pos.x + float(i);
                    if (map->GetBlock(x + i, z) != '0') {
                        map->BreakBlock(x + i, z);
                        posX = true;
                    }
                    cases.push_back(tmpP);
                }
                if (!negX) {
                    tmpP.x = pos.x - float(i);
                    if (map->GetBlock(x - i, z) != '0') {
                        map->BreakBlock(x - i, z);
                        negX = true;
                    }
                    cases.push_back(tmpP);
                }
                tmpP = pos;
                if (!posZ) {
                    tmpP.z = pos.z + float(i);
                    printf("posZ %f %f\n", tmpP.x, tmpP.z);
                    if (map->GetBlock(x, z + i) != '0') {
                        map->BreakBlock(x, z + i);
                        posZ = true;
                    }
                    cases.push_back(tmpP);
                }
                if (!negZ) {
                    tmpP.z = pos.z - float(i);
                    printf("negZ %f %f\n", tmpP.x, tmpP.z);
                    if (map->GetBlock(x, z - i) != '0') {
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
                    if (Vector3Distance(playersPos[i], collide) < .7f) {
                        players[i]->RemoveLive();
                    }
                }
            }
        }
    }

    void GameScript::LoadPlayers(bool populated) {
        std::vector<GamePlayer *> players;
        auto scene = _game->GetScene();
        for (int i = 0; i < 4; i++) {
            auto player = populated ? scene->GetPlayer(i) : scene->PopPlayer();
            player->SetPosition(positions[i]);
            player->SetRotation(rotations[i]);
            player->SetScale(.1f);
            player->SetPlay(false);
            players.push_back(player);
        }
        if (!populated)
            scene->Populate(players);
    }

    void GameScript::ActivateSelection() {
        auto *scene = _game->GetScene();
        scene->SetActiveButton(BUTTON_SELECT, true, true);
        scene->SetActiveButton(BUTTON_AI);
        scene->SetActiveButton(BUTTON_LOAD, false);
        _game->GetScene()->GetText(0)->SetActive(false);
        _game->GetScene()->GetText(1)->SetActive(false);
        _game->GetScene()->GetText(2)->SetActive(true);
    }
}
