/*
** EPITECH PROJECT, 2022
** Scene.cpp
** File description:
** TODO
*/

#include "Scene.hpp"

namespace bomberman {
    void Scene::AddEntity(IEntity *entity) {
        auto camera = dynamic_cast<GameCamera *>(entity);
        if (camera)
            GameCameras.push_back(camera);

        auto object = dynamic_cast<IObject *>(entity);
        if (object)
            GameObjects.push_back(object);

        auto sound = dynamic_cast<GameSound *>(entity);
        if (sound)
            GameSounds.push_back(sound);

        auto text = dynamic_cast<GameText *>(entity);
        if (text)
            GameTexts.push_back(text);
    }

    void Scene::StartScene() {
        for (auto sound: GameSounds)
            sound->Play();
        GameCameras.front()->SetMode(CAMERA_ORBITAL);
    }

    void Scene::DrawScene() {
        GameCamera *camera = GameCameras.front();
        camera->Update();
        BeginMode3D(camera->GetCamera());
        DrawGrid(15, 1.0);
        for (auto object: GameObjects) {
            object->Update();
            object->Draw();
        }
        EndMode3D();
        for (auto text: GameTexts) {
            text->Update();
            text->Draw();
        }
    }
}