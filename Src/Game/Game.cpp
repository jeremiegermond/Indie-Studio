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
        MySound::closeAudioDevice();
        Window::closeWindow();
    }

    void Game::createWindow() {
        Window::initWindow(width, height, "Bomberman");
        // SetWindowMonitor(1);
        rlDisableBackfaceCulling();
        Window::setConfigFlags(FLAG_MSAA_4X_HINT);
        MySound::initAudioDevice();
        Window::setTargetFPS(60);
        flavicon = Load::loadImage("../Assets/Bomb/bombFlavicon.png");
        Window::setIcon(flavicon);
        std::srand(std::time(nullptr));
        try {
            scenes = SceneManager(this);
        } catch (Exception &e) {
            std::cout << e.what() << std::endl;
            throw (CriticalError("Loading failed, aborting.", __FILE__, __LINE__));
        }
    }

    void Game::run() {
        Shader shader = Load::loadShader(nullptr, TextFormat("../Assets/Shaders/bloom.fs", 330));
        RenderTexture2D target = Load::loadRenderTexture(width, height);
        auto rTarget = MyRectangle{0, 0, float(width), float(-height)};

        while (!Window::shouldClose()) {
            Draw::beginTextureMode(target);
            Draw::clearBackground(BLACK);
            GetScene()->DrawScene();
            scenes.GetScene(2)->Draw2DAssets();
            if (scenes.GetScene(2)->GetButton(0)->GetState()) {
                scenes.GetScene(3)->Draw2DAssets();
                scenes.GetScene(3)->GetScript(0)->Update();
            }
            if (scenes.GetScene(0)->GetButton(0)->GetState()) {
                scenes.GetScene(4)->Draw2DAssets();
                if (scenes.GetScene(4)->GetButton(0)->GetState()) {
                    scenes.GetScene(0)->GetButton(0)->SetState(false);
                    scenes.GetScene(4)->GetButton(0)->SetState(false);
                }
            }
            Draw::endTextureMode();
            Draw::beginDrawing();
            Draw::clearBackground(BLACK);
            if (scenes.GetScene(0)->GetButton(1)->GetState()) {
                Draw::beginShaderMode(shader);
                Draw::drawTextureRec(target.texture, rTarget, MyVector2{0, 0}, WHITE);
                Draw::endShaderMode();
            } else {
                Draw::drawTextureRec(target.texture, rTarget, MyVector2{0, 0}, WHITE);
            }
            Draw::endDrawing();
        }
        CloseGame();
    }

    void Game::ChangeScene(int i) {
        GetScene()->UnloadScene();
        Window::setMouseCursor(MOUSE_CURSOR_DEFAULT);
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
        for (int i = 0; i < 4; i++) {
            auto player = scenes.GetScene(1)->GetPlayer(i);
            if (player)
                player->SavePlayer(i);
        }
    }
}