/*
** EPITECH PROJECT, 2022
** game.cpp
** File description:
** TODO
*/

#include "game.hpp"

namespace bomberman {
    Game::Game() {
        this->width = 1920;
        this->height = 1080;
        this->count = 1;
        this->cam_angle = 50;
        this->cam_radius = 1.57;
        this->animFrameCounter = 0;
        this->camera.position = (Vector3){ -20, 5, -15};
        this->camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
        this->camera.up = (Vector3){ 0.0f, 2.0f, 0.0f };
        this->camera.fovy = 90.0f;
        this->camera.projection = CAMERA_PERSPECTIVE;
    }

    Game::~Game() {
        for (unsigned int i = 0; i < count; i++) {
            UnloadModelAnimation(animation[i]);
        }
        RL_FREE(animation);
        UnloadTexture(texture);
        UnloadModel(model);
        CloseWindow();
    }

    void Game::run() {
        InitWindow(this->width, this->height, "Indie Studio");
        this->model = LoadModel("../assets/model.iqm");
        this->texture = LoadTexture("../assets/txr_model.png");
        this->animation = LoadModelAnimations("../assets/model.iqm", &count);
        SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, this->texture);
        SetCameraMode(this->camera, CAMERA_CUSTOM);
        SetTargetFPS(60);

        while (!WindowShouldClose()) {
            UpdateCamera(&camera);
            if (IsKeyDown('Q')) {
                this->cam_angle += 0.02;
            }
            if (IsKeyDown('E')) {
                this->cam_angle -= 0.02;
            }
            this->camera.position.x = cam_radius * std::cos(this->cam_angle);
            this->camera.position.z = cam_radius * std::sin(this->cam_angle);
            UpdateModelAnimation(model, this->animation[0], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= this->animation[0].frameCount) {
                animFrameCounter = 0;
            }

            BeginDrawing();
            BeginMode3D(camera);
            ClearBackground(BLACK);
            DrawModel(model, (Vector3){0, 1, 0}, 1, WHITE);

            DrawGrid(15, 1.0);
            EndMode3D();
            EndDrawing();
        }
    }

}