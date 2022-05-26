/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** main
*/

#include "Main.hpp"

int main() {
    try {
        bomberman::Game game;

        game.createWindow();
        game.run();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {}
    return 0;
}