/*
** EPITECH PROJECT, 2022
** SceneManager.hpp
** File description:
** TODO
*/
#ifndef BOMBERMAN_SCENEMANAGER_HPP
#define BOMBERMAN_SCENEMANAGER_HPP

#include "Scene.hpp"

namespace bomberman {
    class Game;
    class SceneManager {
    private:
        std::vector<Scene *> scenes;
        Game *gameRef{};

    public:
        SceneManager() = default;

        virtual ~SceneManager() = default;

        void LoadScenes(Game *game);

        void CreateMenuScene();

        void CreateLevelScene();

        Scene *GetScene(int sceneId);
    };
}

#endif //BOMBERMAN_SCENEMANAGER_HPP
