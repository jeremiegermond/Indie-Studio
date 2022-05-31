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
        if (camera) {
            GameCameras.push_back(camera);
            return;
        }

        auto player = dynamic_cast<GamePlayer *>(entity);
        if (player) {
            PlayerQueue.push_back(player);
            return;
        }

        auto object = dynamic_cast<IObject *>(entity);
        if (object) {
            GameObjects.push_back(object);
            return;
        }

        auto sound = dynamic_cast<GameSound *>(entity);
        if (sound) {
            GameSounds.push_back(sound);
            return;
        }

    }

    void Scene::StartScene() {
        for (auto sound: GameSounds)
            sound->Play();
        std::cout << "PQueue size: " << PlayerQueue.size() << std::endl;
        GameCameras.front()->SetMode(CAMERA_ORBITAL);
        Players.push_back(PlayerQueue.front());
        PlayerQueue.erase(PlayerQueue.begin());

        std::cout << "P size: " << Players.size() << std::endl;
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
        if (IsKeyPressed(KEY_L)) {
            Players.push_back(PlayerQueue.front());
            PlayerQueue.erase(PlayerQueue.begin());
            PlayerQueue.push_back(Players.front());
            Players.erase(Players.begin());
        }

        for (auto player: Players) {
            player->Update();
            player->Draw();
        }
        EndMode3D();
    }
}