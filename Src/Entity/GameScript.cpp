/*
** EPITECH PROJECT, 2022
** GameScript.cpp
** File description:
** GameScript
*/

#include "GameScript.hpp"
#include "Game.hpp"

namespace bomberman {
    GameScript::GameScript(Game *game, int nbScript) {
       _nbScript = nbScript;
       _game = game;
    }

    void GameScript::Update() {
        switch(_nbScript) {
            case 1:
                PressEnterToPlay();
                break;
            case 2:
                FinishSelectGoToPlay();
                break;
            default:
                break;
        }
    }

    void GameScript::SetActive(bool activate) {
        active = activate;
    }

    void GameScript::Reset() {}

    void GameScript::Move(MyVector3 velocity) {
        (void)velocity;
    }

    void GameScript::PressEnterToPlay() {
        if (IsKeyPressed(KEY_ENTER)) {
            _game->ChangeScene(1);
        }
    }
    void GameScript::FinishSelectGoToPlay() {
        PressEnterToPlay();
    }
}
