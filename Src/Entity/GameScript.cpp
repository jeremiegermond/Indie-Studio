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
            _game->GetScene()->ChangeCamera = true;
            currentScript = 2;
        }
    }
    void GameScript::PressToPlay() {
        if (IsKeyPressed(KEY_ENTER)) {
            _game->ChangeScene(1);
        }
    }
}
