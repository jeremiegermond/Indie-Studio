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
        powerUpPos.emplace_back(175.0f, 355.0f);
        powerUpPos.emplace_back(175.0f, 755.0f);
        powerUpPos.emplace_back(1635.0f, 355.0f);
        powerUpPos.emplace_back(1635.0f, 755.0f);
        gamepads = std::vector({new Gamepad(0), new Gamepad(1), new Gamepad(2), new Gamepad(3)});
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
            case 5:
                WinningScript();
            case 6:
                Settings();
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
        if (IsKeyPressed(KEY_ENTER) || CheckGamepadsButtonPressed(7)) {
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
        if (IsKeyPressed(KEY_ENTER) || CheckGamepadsButtonPressed(7)) {
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
                        if (!player->isCpu()) {
                            player->SetKeys(x);
                            player->SetGamepad(gamepads[x]);
                        }
                        if (i)
                            player->LoadPlayer(x);
                        players.push_back(player);
                    }
                    scene->SetActiveButton(BUTTON_MENU, false, true);
                    _game->ChangeScene(1);
                    scene = _game->GetScene();
                    auto map = scene->GetMap();
                    scene->Populate(players);
                    for (int x = 0; x < 4; x++) {
                        auto player = scene->GetPlayer(x);
                        auto powerUp = scene->GetGamePowerUp(x);
                        powerUp->SetPlayer(player);
                        powerUp->SetPosition(powerUpPos[x]);
                        scene->GetImage(x)->SetColor(WHITE);
                    }
                    scene->GetObject(0)->SetScale(50.f);
                    scene->GetObject(0)->SetPosition(MyVector3{25.f, -5.f, 25.f});
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
        int playerAlive = 4;
        if (btnReturn && btnReturn->GetState()) {
            btnReturn->SetState(false);
            map->Save();
            _game->ChangeScene(0);
            scene = _game->GetScene();
            auto *script = scene->GetScript(0);
            script->currentScript = 2;
            script->ActivateSelection();
            script->LoadPlayers(true);
            scene->SetActiveButton(BUTTON_MENU, true, true);
            scene->GetObject(0)->SetScale(1.f);
            scene->GetObject(0)->SetPosition(MyVector3{0.f, 0.f, 0.f});
            return;
        }
        for (int x = 0; x < 4; x++) {
            auto player = scene->GetPlayer(x);
            if (player == nullptr)
                break;
            if (!player->GetActive()) {
                playerAlive--;
                scene->GetImage(x)->SetColor(GRAY);
            } else {
                players.push_back(player);
                playersPos.push_back(player->GetPosition());
            }
            if (playerAlive == 1 && !players.empty()) {
                auto winner = players.back();
                winner->Reset();
                winner->SetPosition(MyVector3{0.f, 0.f, 0.f});
                winner->SetRotation(MyVector3{0.f, 0.f, 1.8f});
                winner->SetScale(.1f);
                winner->SetPlay(false);
                winner->SetActive(true);
                _game->ChangeScene(5);
                scene = _game->GetScene();
                scene->GetObject(0)->SetScale(1.f);
                scene->Populate(players);
                scene->GetObject(0)->SetPosition(MyVector3{0.f, 0.f, 0.f});
                return;
            }
            else if (playerAlive == 0) {
                std::vector<GamePlayer *> ties;
                for (int i = 0; i < 4; i++) {
                    auto tie = scene->GetPlayer(i);
                    tie->Reset();
                    tie->SetPosition(positions[i]);
                    tie->SetRotation(rotations[i]);
                    tie->SetScale(.1f);
                    tie->SetPlay(false);
                    tie->SetActive(true);
                    ties.push_back(tie);
                }
                _game->ChangeScene(6);
                scene = _game->GetScene();
                scene->GetObject(0)->SetScale(1.f);
                scene->Populate(ties);
                scene->GetObject(0)->SetPosition(MyVector3{0.f, 0.f, 0.f});
                return;
            }
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
            MyVector3 tmpP;
            int fire = bomb->GetFire();
            cases.push_back(pos);
            int x = int(pos.x);
            int z = int(pos.z);
            bool posX = false;
            bool negX = false;
            bool posZ = false;
            bool negZ = false;
            for (int i = 1; i <= fire; i++) {
                tmpP = pos;
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
                    if (map->GetBlock(x, z + i) != '0') {
                        map->BreakBlock(x, z + i);
                        posZ = true;
                    }
                    cases.push_back(tmpP);
                }
                if (!negZ) {
                    tmpP.z = pos.z - float(i);
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
            if (populated)
                player->SavePlayer(i);
            player->Reset();
            player->SetPosition(positions[i]);
            player->SetRotation(rotations[i]);
            player->SetScale(.1f);
            player->SetPlay(false);
            player->SetActive(true);
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

    bool GameScript::CheckGamepadsButtonPressed(int nb) {
        for (int i = 0; i < 4; i++)
            if (gamepads[i]->button(nb))
                return true;
        return false;
    }

    void GameScript::WinningScript() {
        auto scene = _game->GetScene();
        auto btnReturn = scene->GetButton(0);
        if (btnReturn && btnReturn->GetState()) {
            btnReturn->SetState(false);
            _game->ChangeScene(0);
            scene = _game->GetScene();
            auto *script = scene->GetScript(0);
            script->currentScript = 2;
            script->ActivateSelection();
            script->LoadPlayers(true);
            scene->SetActiveButton(BUTTON_MENU, true, true);
        }
    }

    void GameScript::Settings() {
        auto *scene = _game->GetSceneManager().GetScene(3);
        static bool switch_fs = IsWindowFullscreen();
        if (_game->GetSceneManager().GetScene(3)->GetButton(0)->GetState()) {
            _game->GetSceneManager().GetScene(2)->GetButton(0)->SetState(false);
            _game->GetSceneManager().GetScene(3)->GetButton(0)->SetState(false);
        }
        if (!scene->GetButton(2)->GetState())
            SetMasterVolume(0);
        else
            SetMasterVolume(1);
        if (switch_fs != scene->GetButton(1)->GetState()) {
            ToggleFullscreen();
            if (!IsWindowFullscreen()) {
                SetWindowSize(1920, 1050);
            }
        }
        switch_fs = scene->GetButton(1)->GetState();
    }
}
