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
        cam_angle = 0;
        cam_radius = 5;
        camera.position = (Vector3){ 6.0f, 3.0f, 6.0f};
        camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
        camera.up = (Vector3){ 0.0f, 2.0f, 0.0f };
        camera.fovy = 45.0f;
        camera.projection = CAMERA_PERSPECTIVE;
    }

    Game::~Game() {
        UnloadSound(sound);
        CloseAudioDevice();
        CloseWindow();
    }

    void Game::createWindow() {
        InitWindow(width, height, "Indie Studio");
        SetConfigFlags(FLAG_MSAA_4X_HINT);
        InitAudioDevice();
        sound = LoadSound("../Assets/Songs/ForestSong.mp3");
        SetCameraMode(camera, CAMERA_ORBITAL);
        SetTargetFPS(60);
    }

    Scene *Game::createScene() {
        scenes.push_back(new Scene);
        return scenes.back();
    }

    Scene *Game::getScene(int pos) {
        return scenes.back(); // debug
    }

    void Game::run() {
        Shader shader = LoadShader(0, TextFormat("../Assets/Shaders/bloom.fs", 330));
        RenderTexture2D target = LoadRenderTexture(width, height);

        PlaySound(sound);
        while (!WindowShouldClose()) {
            UpdateCamera(&camera);
            Scene *ActualScene = getScene(0);
            for (auto elem : *ActualScene->getElements()) {
                elem->UpdtModelAnim();
                elem->draw(&target, &camera, &map);
            }
            BeginDrawing();
                ClearBackground(BLACK);
                if (IsKeyDown(KEY_B)) {
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

    void Scene::addElement(Element *element) {
        elements.push_back(element);
    }

    void Scene::loadElements() {
        for (auto element : elements)
            element->load();
    }

    std::vector<Element *> *Scene::getElements() {
        return &elements;
    }

    void Element::draw(RenderTexture2D *target, Camera3D *camera, Map *map) {
        BeginTextureMode(*target);
            ClearBackground(BLACK);
            BeginMode3D(*camera);
            map->drawMap();
            DrawModel(model, (Vector3){0, 1, 0}, 1, WHITE);
            DrawGrid(15, 1.0);
            DrawModel(model, (Vector3){0, 1, 0}, 1, WHITE);
            EndMode3D();
        EndTextureMode();
    }

    void Element::UpdtModelAnim() {
        UpdateModelAnimation(model, animation[0], animFrameCounter);
        animFrameCounter++;
        if (animFrameCounter >= animation[0].frameCount)
            animFrameCounter = 0;
    }

    Element::Element(std::string modelPath, std::string texturePath, std::string animPath) {
        count = 1;
        animFrameCounter = 0;
        model_path = modelPath;
        texture_path = texturePath;
        anim_path = animPath;
    }

    Element::~Element() {
        for (unsigned int i = 0; i < count; i++)
            UnloadModelAnimation(animation[i]);
        RL_FREE(animation);
        UnloadTexture(texture);
        UnloadModel(model);
    }

    void Element::load() {
        model = LoadModel(model_path.c_str());
        texture = LoadTexture(texture_path.c_str());
        animation = LoadModelAnimations(anim_path.c_str(), &count);
        SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    }
}