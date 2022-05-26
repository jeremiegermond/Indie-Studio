/*
** EPITECH PROJECT, 2022
** game.cpp
** File description:
** TODO
*/

#include "Game.hpp"

namespace bomberman {
    Game::Game::Game() {
        width = 1920;
        height = 1080;
    }

    Game::~Game() {
        CloseAudioDevice();
        CloseWindow();
    }

    void Game::createWindow() {
        InitWindow(width, height, "Bomberman");
        rlDisableBackfaceCulling();
        SetConfigFlags(FLAG_MSAA_4X_HINT);
        InitAudioDevice();
        SetTargetFPS(60);
        scenes.LoadScenes();
    }

    void Game::run() {
        Shader shader = LoadShader(0, TextFormat("../Assets/Shaders/bloom.fs", 330));
        RenderTexture2D target = LoadRenderTexture(width, height);
        auto rTarget = Rectangle{0, 0, float(width), float(-height)};

        scenes.GetScene(0).StartScene();
        while (!WindowShouldClose()) {
            Scene currentScene = scenes.GetScene(0);
            BeginTextureMode(target);
            ClearBackground(BLACK);
            currentScene.DrawScene();
            EndTextureMode();
            BeginDrawing();
            ClearBackground(BLACK);
            if (IsKeyDown(KEY_B)) {
                DrawTextureRec(target.texture, rTarget, Vector2{0, 0}, WHITE);
            } else {
                BeginShaderMode(shader);
                DrawTextureRec(target.texture, rTarget, Vector2{0, 0}, WHITE);
                EndShaderMode();
            }
            EndDrawing();
        }
    }
}