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
        currentScene = 0;
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
        scenes = SceneManager(this);
    }

    void Game::run() {
        Shader shader = LoadShader(0, TextFormat("../Assets/Shaders/bloom.fs", 330));
        RenderTexture2D target = LoadRenderTexture(width, height);
        auto rTarget = Rectangle{0, 0, float(width), float(-height)};

        while (!WindowShouldClose()) {
            BeginTextureMode(target);
            ClearBackground(BLACK);
            GetScene()->DrawScene();
            EndTextureMode();
            BeginDrawing();
            ClearBackground(BLACK);
            if (IsKeyDown(KEY_B)) {
                BeginShaderMode(shader);
                DrawTextureRec(target.texture, rTarget, MyVector2{0, 0}, WHITE);
                EndShaderMode();
            } else {
                DrawTextureRec(target.texture, rTarget, MyVector2{0, 0}, WHITE);
            }
            EndDrawing();
        }
    }

    void Game::ChangeScene(int i) {
        GetScene()->UnloadScene();
        currentScene = i;
        GetScene()->StartScene();
    }

    Scene *Game::GetScene() {
        return scenes.GetScene(currentScene);
    }
}