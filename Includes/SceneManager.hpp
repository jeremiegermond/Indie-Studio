/*
** EPITECH PROJECT, 2022
** SceneManager.hpp
** File description:
** TODO
*/
#ifndef BOMBERMAN_SCENEMANAGER_HPP
#define BOMBERMAN_SCENEMANAGER_HPP

#pragma once
#include "Scene.hpp"
#include "Game.hpp"

namespace bomberman {
    class SceneManager {
    private:
//        int currentScene{};
        std::vector<Scene> scenes;
        Game *gameRef;

    public:
        SceneManager() = default;
        virtual ~SceneManager() = default;
        void LoadScenes(Game *game);
        void CreateMenuScene();
        void CreateLevelScene();

        Scene GetScene(int sceneId);
    };
}

#endif //BOMBERMAN_SCENEMANAGER_HPP
