/*
** EPITECH PROJECT, 2022
** Scene.cpp
** File description:
** TODO
*/

#include "Scene.hpp"

namespace bomberman {
    void Scene::addGameObject(GameObject *GameObject) {
        GameObjects.push_back(GameObject);
    }

    void Scene::loadGameObjects() {
        for (auto GameObject : GameObjects)
            GameObject->load();
    }

    std::vector<GameObject *> *Scene::getGameObjects() {
        return &GameObjects;
    }
}