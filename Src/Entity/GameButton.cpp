/*
** EPITECH PROJECT, 2022
** GameButton.cpp
** File description:
** TODO
*/
#include "GameButton.hpp"

namespace bomberman {
    GameButton::GameButton(std::string onTexture,
                           std::string offTexure) {
        texture = LoadTexture(onTexture.c_str());
    }

    GameButton::~GameButton() {

    }

    void GameButton::Update() {

    }

    void GameButton::Draw() {

    }
}
