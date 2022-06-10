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

        auto bomb = dynamic_cast<GameBomb *>(entity);
        if (bomb) {
            GameBombs.push_back(bomb);
            return;
        }

        auto player = dynamic_cast<GamePlayer *>(entity);
        if (player) {
            PlayerQueue.push_back(player);
            return;
        }

        auto object = dynamic_cast<GameObject *>(entity);
        if (object) {
            GameObjects.push_back(object);
            return;
        }

        auto sound = dynamic_cast<GameSound *>(entity);
        if (sound) {
            GameSounds.push_back(sound);
            return;
        }

        auto text = dynamic_cast<GameText *>(entity);
        if (text) {
            GameTexts.push_back(text);
            return;
        }

        auto script = dynamic_cast<GameScript *>(entity);
        if (script) {
            GameScripts.push_back(script);
            return;
        }

        auto drawmap = dynamic_cast<GameDrawMap *>(entity);
        if (drawmap) {
            GameDrawMaps.push_back(drawmap);
            return;
        }

        auto image = dynamic_cast<GameImage *>(entity);
        if (image) {
            GameImages.push_back(image);
            return;
        }

        auto button = dynamic_cast<GameButton *>(entity);
        if (button) {
            GameButtons.push_back(button);
            return;
        }
    }

    void Scene::StartScene() {
        for (auto sound: GameSounds)
            sound->Play();
    }

    void Scene::DrawScene(Model skybox) {
        for (auto script: GameScripts) {
            script->Update();
        }
        Start3D();
        Draw3DAssets();
        EndMode3D();
        Draw2DAssets();
    }

    void Scene::Draw3DAssets() {
        // rlDisableDepthMask();
        // DrawModel(skybox, (Vector3){0, 0, 0}, 1.0f, WHITE);
        // rlEnableDepthMask();
        // DrawGrid(15, 1.0);
        for (auto object: GameObjects) {
            object->Update();
            object->Draw();
        }
        for (auto player: Players) {
            player->Update();
            player->Draw();
        }
        for (auto drawmap: GameDrawMaps) {
            drawmap->Draw();
        }
        for (auto bomb: GameBombs) {
            bomb->Update();
            bomb->Draw();
            if (!bomb->GetActive())
                PopBomb();
            if (bomb->GetExplode())
                continue;
        }
    }

    void Scene::Draw2DAssets() {
        for (auto image: GameImages) {
            image->Draw();
        }
        for (auto text: GameTexts) {
            text->Update();
            text->Draw();
        }
        for (auto button: GameButtons) {
            button->Update();
            button->Draw();
        }
    }

    void Scene::UnloadScene() {
        for (auto sound : GameSounds)
            sound->Stop();
    }

    GameCamera *Scene::GetCamera(int i) {
        return GameCameras.at(i);
    }

    GameText *Scene::GetText(int i) {
        return GameTexts.at(i);
    }

    GamePlayer *Scene::GetPlayer(int i) {
        return  Players.at(i);
    }

    GamePlayer *Scene::PopPlayer(GamePlayer *push) {
        GamePlayer *pop = PlayerQueue.front();
        PlayerQueue.erase(PlayerQueue.begin());
        if (push != nullptr)
            PlayerQueue.push_back(push);
        return pop;
    }

    void Scene::Populate(const std::vector<GamePlayer *>& newPlayers) {
        for (auto player: newPlayers)
            Players.push_back(player);
    }

    std::vector<GameButton *> Scene::GetButtons() {
        return GameButtons;
    }

    GameButton *Scene::GetButton(int i) {
        return GameButtons.at(i);
    }

    void Scene::ChangePlayer(int i) {
        Players[i] = PopPlayer(Players[i]);
    }

    void Scene::Start3D() {
        if (CamSwitch)
            MoveCamera();
        auto *camera = GameCameras.front();
        camera->Update();
        BeginMode3D(camera->GetCamera());
    }

    void Scene::NextCamera() {
        if (GameCameras.size() > 1) {
            GameCameras[0]->SetObjectiveCam(GameCameras[1]->GetCamera());
            CamSwitch = true;
        }
    }

    void Scene::MoveCamera() {
        GameCamera *camera = GameCameras[0];
        GameCamera *newCam = GameCameras[1];
        if (CamSwitch && Vector3Distance(camera->GetCamera().position, newCam->GetStartPosition()) < 0.5f) {
            CamSwitch = false;
            GameCameras.push_back(camera);
            GameCameras.erase(GameCameras.begin());
            camera->Reset();
        }
    }

    void Scene::PopBomb() {
        if (GameBombs.empty())
            return;
        GameBombs.erase(GameBombs.begin());
    }
}