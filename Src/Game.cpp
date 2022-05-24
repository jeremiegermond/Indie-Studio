/*
** EPITECH PROJECT, 2022
** game.cpp
** File description:
** TODO
*/

#include "Game.hpp"

namespace bomberman {
    Game::Game() {
        this->width = 1920;
        this->height = 1080;
        this->count = 1;
        this->cam_angle = 0;
        this->cam_radius = 5;
        this->animFrameCounter = 0;
        this->camera.position = (Vector3){ 6.0f, 3.0f, 6.0f};
        this->camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
        this->camera.up = (Vector3){ 0.0f, 2.0f, 0.0f };
        this->camera.fovy = 45.0f;
        this->camera.projection = CAMERA_PERSPECTIVE;
    }

    Game::~Game() {
        for (unsigned int i = 0; i < count; i++) {
            UnloadModelAnimation(animation[i]);
        }
        RL_FREE(animation);
        UnloadSound(this->sound);
        UnloadTexture(texture);
        UnloadModel(model);
        CloseAudioDevice();
        CloseWindow();
    }

    void Game::loadObjects() {
        SetConfigFlags(FLAG_MSAA_4X_HINT);
        InitWindow(this->width, this->height, "Indie Studio");
        InitAudioDevice();

        this->model = LoadModel("../Assets/model.iqm");
        this->texture = LoadTexture("../Assets/txr_model.png");
        this->animation = LoadModelAnimations("../Assets/model.iqm", &count);
        this->sound = LoadSound("../Assets/Songs/ForestSong.mp3");

        SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, this->texture);
        SetCameraMode(this->camera, CAMERA_ORBITAL);
        SetTargetFPS(60);
    }

    void Game::run() {
        Shader shader = LoadShader(0, TextFormat("../Assets/Shaders/bloom.fs", 330));
        RenderTexture2D target = LoadRenderTexture(this->width, this->height);
        while (!WindowShouldClose()) {
            UpdateCamera(&camera);
//            if (IsKeyDown('Q')) {
//                this->cam_angle += 0.02;
//            }
//            if (IsKeyDown('E')) {
//                this->cam_angle -= 0.02;
//            }
//            this->camera.position.x = cam_radius * std::cos(this->cam_angle);
//            this->camera.position.z = cam_radius * std::sin(this->cam_angle);

            UpdateModelAnimation(model, this->animation[0], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= this->animation[0].frameCount) {
                animFrameCounter = 0;
            }
            if (IsKeyPressed(KEY_SPACE)) {
                PlaySound(this->sound);
            }

            BeginTextureMode(target);
                ClearBackground(BLACK);
                BeginMode3D(camera);
                this->map.drawMap();
                DrawModel(model, (Vector3){0, 1, 0}, 1, WHITE);
                DrawGrid(15, 1.0);
                EndMode3D();
            EndTextureMode();

            BeginDrawing();
                ClearBackground(BLACK);
                if (IsKeyPressed(KEY_B)) {
                    DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);
                }
                else {
                    BeginShaderMode(shader);
                        DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);
                    EndShaderMode();
                }
            EndDrawing();
        }
    }

}