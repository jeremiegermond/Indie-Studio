/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** main
*/

#include "Main.hpp"

int main()
{
    bomberman::Game game;

    game.createWindow();
    auto scene = game.createScene();
//    scene->addGameObject(new bomberman::GameObject("../Assets/model.iqm", "../Assets/txr_model.png", "../Assets/model.iqm"));
    scene->addGameObject(new bomberman::GameObject("../Assets/Level/forest.obj"));
    scene->loadGameObjects();
    game.run();
    return 0;
}