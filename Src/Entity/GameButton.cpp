/*
** EPITECH PROJECT, 2022
** GameButton.cpp
** File description:
** TODO
*/
#include "GameButton.hpp"

namespace bomberman {
    GameButton::GameButton(int x,
                           int y,
                           const std::string &onPath,
                           const std::string &offPath,
                           int type)
            : posX(x), posY(y), type(type) {
        onTexture = LoadTexture(onPath.c_str());
        offTexture = LoadTexture(offPath.c_str());
        active = type == BUTTON_MENU;
        state = false;
        collision = Rectangle{float(posX), float(posY), float(onTexture.width), float(onTexture.height)};
        tint = WHITE;
    }

    GameButton::~GameButton() {
        UnloadTexture(onTexture);
        UnloadTexture(offTexture);
    }

    void GameButton::Update() {
        if (active) {
            if (CheckCollisionPointRec(GetMousePosition(), collision)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    state = !state;
                } else {
                    tint = GRAY;
                    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
                }
            } else {
                tint = WHITE;
                SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            }
        }
    }

    void GameButton::Draw() {
        if (active) {
            if (state) {
                DrawTexture(onTexture, posX, posY, tint);
            } else {
                DrawTexture(offTexture, posX, posY, tint);
            }
        }
    }

    void GameButton::SetState(bool newState) {
        state = newState;
    }

    bool GameButton::GetState() const {
        return state;
    }

    void GameButton::SetActive(bool activated) {
        active = activated;
    }

    int GameButton::GetType() const {
        return type;
    }
}
