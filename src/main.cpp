/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** main
*/

#include "main.hpp"

int main() {
    InitWindow(800, 600, "Bomberman");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Bomberman", 900, 0, 16, RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
}