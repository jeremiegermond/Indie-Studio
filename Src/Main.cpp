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
    scene->addElement(new bomberman::Element("../Assets/model.iqm", "../Assets/txr_model.png", "../Assets/model.iqm"));
    scene->loadElements();
    game.run();
    return 0;
}