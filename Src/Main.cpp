/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** main
*/

#include "Main.hpp"
#include "Exception.hpp"

int main() {
    try {
        bomberman::Game game;

        game.createWindow();
        game.run();
    } catch (bomberman::CriticalError &e) {
        std::cout << "Critical Error : " << e.what() << std::endl;
    } catch (...) {}
    return 0;
}