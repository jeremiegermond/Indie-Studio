/*
** EPITECH PROJECT, 2022
** Scene.cpp
** File description:
** TODO
*/

#include "Scene.hpp"

namespace bomberman {
    void Scene::AddGameObject(IObject *GameObject) {
        GameObjects.push_back(GameObject);
    }

    void Scene::AddSound(Sound sound) {
        GameSounds.push_back(sound);
    }

    void Scene::StartScene() {
        for (auto sound: GameSounds)
            PlaySound(sound);
    }

    void Scene::DrawScene() {
        for (auto object : GameObjects) {
            object->Update();
            object->Draw();
        }
    }
}