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
        onTexture = Load::loadTexture(onPath.c_str());
        offTexture = Load::loadTexture(offPath.c_str());
        active = type == BUTTON_MENU;
        state = false;
        collision = MyRectangle{float(posX), float(posY), float(onTexture.width), float(onTexture.height)};
        tint = WHITE;
        click = MySound::loadSound("../Assets/Bomb/click.mp3");
    }

    GameButton::~GameButton() {
        Load::unloadTexture(onTexture);
        Load::unloadTexture(offTexture);
    }

    void GameButton::Update() {
        if (active) {
            if (Load::checkCollisionPointRec(MyGamepad::getMousePosition(), collision)) {
                if (MyGamepad::isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    state = !state;
                    MySound::playSound(click);
                } else {
                    tint = GRAY;
                }
                hover = true;
            } else {
                tint = WHITE;
                hover = false;
            }
        }
    }

    void GameButton::Draw() {
        if (active) {
            if (state) {
                Draw::drawTexture(onTexture, posX, posY, tint);
            } else {
                Draw::drawTexture(offTexture, posX, posY, tint);
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

    bool GameButton::GetHover() const {
        return hover;
    }
}
