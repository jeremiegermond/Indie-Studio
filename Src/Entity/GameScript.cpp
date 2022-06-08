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
            _game->GetScene()->ChangeCamera = true;
            _game->GetScene()->GetText(0)->SetActive(false);
            _game->GetScene()->GetText(1)->SetActive(false);
            _game->GetScene()->GetText(2)->SetActive(true);
            auto buttons = _game->GetScene()->GetButtons();
            for (auto button: buttons) {
                if (button->GetType() == BUTTON_SELECT) {
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
            players.push_back(_game->GetScene()->GetPlayer(0));
            players.push_back(_game->GetScene()->GetPlayer(1));
            players.push_back(_game->GetScene()->GetPlayer(2));
            players.push_back(_game->GetScene()->GetPlayer(3));
            _game->ChangeScene(1);
            _game->GetScene()->Populate(players);
        }
    }
}
