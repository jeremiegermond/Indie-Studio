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

        auto powerup = dynamic_cast<GamePowerUp *>(entity);
        if (powerup) {
            GamePowerUps.push_back(powerup);
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

        auto gameMap = dynamic_cast<GameDrawMap *>(entity);
        if (gameMap) {
            GameMap = gameMap;
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

    void Scene::DrawScene() {
        for (auto music: GameSounds)
            music->Update();
        for (auto script: GameScripts) {
            script->Update();
        }
        Start3D();
        Draw3DAssets();
        EndMode3D();
        Draw2DAssets();
    }

    void Scene::Draw3DAssets() {
        for (auto object: GameObjects) {
            object->Update();
            object->Draw();
        }
        for (auto player: Players) {
            player->Update();
            player->Draw();
        }
        if (GameMap)
            GameMap->Draw();
    }

    void Scene::Draw2DAssets() {
        for (auto image: GameImages) {
            image->Draw();
        }
        for (auto text: GameTexts) {
            text->Update();
            text->Draw();
        }
        for (auto powerup: GamePowerUps) {
            powerup->Update();
            powerup->Draw();
        }
        bool hover = false;
        for (auto button: GameButtons) {
            button->Update();
            button->Draw();
            hover += button->GetHover();
        }
        SetCursor(hover);
    }

    void Scene::UnloadScene() {
        for (auto sound: GameSounds)
            sound->Stop();
    }

    GameCamera *Scene::GetCamera(int i) {
        if (GameCameras.size() <= size_t(i))
            return nullptr;
        return GameCameras.at(i);
    }

    GameText *Scene::GetText(int i) {
        if (GameTexts.size() <= size_t(i))
            return nullptr;
        return GameTexts.at(i);
    }

    GamePlayer *Scene::GetPlayer(int i) {
        if (Players.size() <= size_t(i))
            return nullptr;
        return Players.at(i);
    }

    GameImage *Scene::GetImage(int i) {
        if (GameImages.size() <= size_t(i))
            return nullptr;
        return GameImages.at(i);
    }

    GamePlayer *Scene::PopPlayer(GamePlayer *push) {
        GamePlayer *pop = PlayerQueue.front();
        PlayerQueue.erase(PlayerQueue.begin());
        if (push != nullptr)
            PlayerQueue.push_back(push);
        return pop;
    }

    void Scene::Populate(const std::vector<GamePlayer *> &newPlayers) {
        if (!Players.empty())
            Players.clear();
        for (auto player: newPlayers) {
            player->SetMap(GameMap);
            Players.push_back(player);
        }
    }

    std::vector<GameButton *> Scene::GetButtons() {
        return GameButtons;
    }

    GameButton *Scene::GetButton(int i) {
        if (GameButtons.size() <= size_t(i))
            return nullptr;
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

    GameDrawMap *Scene::GetMap() {
        return GameMap;
    }

    void Scene::SetCursor(bool hover) {
        if (Hover == hover)
            return;
        Hover = hover;
        if (hover)
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    GameScript *Scene::GetScript(int i) {
        if (GameScripts.size() <= size_t(i))
            return nullptr;
        return GameScripts.at(i);
    }

    void Scene::SetActiveButton(ButtonType type,
                                bool active,
                                bool reset) {
        for (auto button: GameButtons) {
            if (button->GetType() == type) {
                button->SetActive(active);
                if (reset)
                    button->SetState(false);
            }
        }
    }

    GamePowerUp *Scene::GetGamePowerUp(int i) {
        if (GamePowerUps.size() <= size_t(i))
            return nullptr;
        return GamePowerUps.at(i);
    }

    GameObject *Scene::GetObject(int i) {
        if (GameObjects.size() <= size_t(i))
            return nullptr;
        return GameObjects.at(i);
    }
}