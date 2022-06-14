/*
** EPITECH PROJECT, 2022
** game.cpp
** File description:
** TODO
*/

#include "Game.hpp"
#include "Exception.hpp"

namespace bomberman {
    Game::Game() {
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
        flavicon = LoadImage("../Assets/Bomb/bombFlavicon.png");
        SetWindowIcon(flavicon);
        std::srand(std::time(nullptr));
        try {
            scenes = SceneManager(this);
        } catch (Exception &e) {
            std::cout << "Build error :" << e.what() << std::endl;
            throw (CriticalError("Loading failed, aborting.", __FILE__, __LINE__));
        }
    }

    void Game::run() {
        Shader shader = LoadShader(0, TextFormat("../Assets/Shaders/bloom.fs", 330));
        RenderTexture2D target = LoadRenderTexture(width, height);
        auto rTarget = Rectangle{0, 0, float(width), float(-height)};

        while (!WindowShouldClose()) {
            BeginTextureMode(target);
            ClearBackground(BLACK);
            GetScene()->DrawScene();
            scenes.GetScene(2)->Draw2DAssets();
            if (scenes.GetScene(2)->GetButton(0)->GetState()) {
                scenes.GetScene(3)->Draw2DAssets();
                if (scenes.GetScene(3)->GetButton(0)->GetState()) {
                    scenes.GetScene(2)->GetButton(0)->SetState(false);
                    scenes.GetScene(3)->GetButton(0)->SetState(false);
                }
            }
            if (scenes.GetScene(0)->GetButton(0)->GetState()) {
                scenes.GetScene(4)->Draw2DAssets();
                if (scenes.GetScene(4)->GetButton(0)->GetState()) {
                    scenes.GetScene(0)->GetButton(0)->SetState(false);
                    scenes.GetScene(4)->GetButton(0)->SetState(false);
                }
            }
            EndTextureMode();
            BeginDrawing();
            ClearBackground(BLACK);
            if (scenes.GetScene(0)->GetButton(1)->GetState()) {
                BeginShaderMode(shader);
                DrawTextureRec(target.texture, rTarget, MyVector2{0, 0}, WHITE);
                EndShaderMode();
            } else {
                DrawTextureRec(target.texture, rTarget, MyVector2{0, 0}, WHITE);
            }
            EndDrawing();
        }
        CloseGame();
    }

    void Game::ChangeScene(int i) {
        GetScene()->UnloadScene();
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        currentScene = i;
        GetScene()->StartScene();
    }

    Scene *Game::GetScene() {
        return scenes.GetScene(currentScene);
    }

    SceneManager Game::GetSceneManager() {
        return scenes;
    }

    void Game::CloseGame() {
        scenes.GetScene(1)->GetMap()->Save();
        for (int i = 0; i < 4; i++)
            scenes.GetScene(1)->GetPlayer(i)->SavePlayer(i);

    }
}