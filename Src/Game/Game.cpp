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
        GameText text("../Assets/Font/Beauty_Forest.free.ttf", "Loading...", 855, 400, 125, WHITE);
        BeginDrawing();
        ClearBackground(BLACK);
        text.Draw();
        EndDrawing();
        scenes = SceneManager(this);
    }

    void Game::run() {
        Shader shader = LoadShader(0, TextFormat("../Assets/Shaders/bloom.fs", 330));
        RenderTexture2D target = LoadRenderTexture(width, height);
        auto rTarget = Rectangle{0, 0, float(width), float(-height)};

        Mesh cube = GenMeshCube(1.0f, 1.0f, 1.0f);
        Model skybox = LoadModelFromMesh(cube);


        skybox.materials[0].shader = LoadShader("../Assets/Shaders/skybox.vs", "../Assets/Shaders/skybox.fs");

        int t[1] = {MATERIAL_MAP_CUBEMAP};
        int x[1] =  { 0 };
        int y[1] = { 0 };

        SetShaderValue(skybox.materials[0].shader, GetShaderLocation(skybox.materials[0].shader, "environmentMap"), t, SHADER_UNIFORM_INT);
        SetShaderValue(skybox.materials[0].shader, GetShaderLocation(skybox.materials[0].shader, "doGamma"), x, SHADER_UNIFORM_INT);
        SetShaderValue(skybox.materials[0].shader, GetShaderLocation(skybox.materials[0].shader, "vflipped"), y, SHADER_UNIFORM_INT);

        Image img = LoadImage("../Assets/Level/skybox.png");
        skybox.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = LoadTextureCubemap(img, CUBEMAP_LAYOUT_AUTO_DETECT);
        UnloadImage(img);
        while (!WindowShouldClose()) {
            BeginTextureMode(target);
            ClearBackground(BLACK);
            GetScene()->DrawScene(skybox);
            scenes.GetScene(2)->Draw2DAssets();
            if (scenes.GetScene(2)->GetButton(0)->GetState()) {
                scenes.GetScene(3)->Draw2DAssets();
                if (scenes.GetScene(3)->GetButton(1)->GetState()) {
                    scenes.GetScene(2)->GetButton(0)->SetState(false);
                    scenes.GetScene(3)->GetButton(1)->SetState(false);
                }
            }
            if (scenes.GetScene(0)->GetButton(0)->GetState()) {
                scenes.GetScene(4)->Draw2DAssets();
                if (scenes.GetScene(4)->GetButton(0)->GetState()) {
                    scenes.GetScene(0)->GetButton(0)->SetState(false);
                    scenes.GetScene(4)->GetButton(0)->SetState(false);
                }
            }
            if (IsKeyPressed(KEY_P)) {
                printf("x:%f y:%f\n", GetMousePosition().x, GetMousePosition().y);
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
    }

    void Game::ChangeScene(int i) {
        GetScene()->UnloadScene();
        currentScene = i;
        GetScene()->StartScene();
    }

    Scene *Game::GetScene() {
        return scenes.GetScene(currentScene);
    }

    SceneManager Game::GetSceneManager() {
        return scenes;
    }
}