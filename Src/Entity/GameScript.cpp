/*
** EPITECH PROJECT, 2022
** GameScript.cpp
** File description:
** GameScript
*/

#include "GameScript.hpp"
#include "Game.hpp"

namespace bomberman {
    GameScript::GameScript(Game *game, int script) {
        currentScript = script;
       _game = game;
       active = true;
    }

    void GameScript::Update() {
        if (!active)
            return;
        switch(currentScript) {
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
            players.push_back(_game->GetScene()->PopPlayer());
            players.back()->SetPosition(MyVector3 {-.47f, 0.0f, -.79f});
            players.back()->SetRotation(MyVector3 {.0f, .0f, 1.5f});
            players.push_back(_game->GetScene()->PopPlayer());
            players.back()->SetPosition(MyVector3 {-.44f, 0.0f, -.54f});
            players.back()->SetRotation(MyVector3 {.0f, .0f, 1.5f});
            players.push_back(_game->GetScene()->PopPlayer());
            players.back()->SetPosition(MyVector3 {-.65f, 0.0f, -.1f});
            players.back()->SetRotation(MyVector3 {.0f, .0f, 3.0f});
            players.push_back(_game->GetScene()->PopPlayer());
            players.back()->SetPosition(MyVector3 {-.88f, 0.0f, -.06f});
            players.back()->SetRotation(MyVector3 {.0f, .0f, 3.0f});
            _game->GetScene()->Populate(players);
            _game->GetScene()->GetCamera(0)->SetMode(CAMERA_CUSTOM);
            _game->GetScene()->ChangeCamera = true;
            _game->GetScene()->GetText(0)->SetActive(false);
            _game->GetScene()->GetText(1)->SetActive(false);
            _game->GetScene()->GetText(2)->SetActive(true);
            currentScript = 2;
        }
    }
    void GameScript::PressToPlay() {
        if (IsKeyPressed(KEY_ENTER)) {
            std::vector<GamePlayer *> players;
            players.push_back(_game->GetScene()->GetPlayer(0));
            players.push_back(_game->GetScene()->GetPlayer(1));
            players.push_back(_game->GetScene()->GetPlayer(2));
            players.push_back(_game->GetScene()->GetPlayer(3));
            _game->ChangeScene(1);
            _game->GetScene()->Populate(players);
        }
        std::vector<Rectangle>
    }
}
