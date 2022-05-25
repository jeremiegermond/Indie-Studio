/*
** EPITECH PROJECT, 2022
** {FILENAME}
** File description:
** TODO
*/
#ifndef BOMBERMAN_SCENE_HPP
#define BOMBERMAN_SCENE_HPP

#include <vector>
#include "GameObject.hpp"


namespace bomberman {
    class Scene {
    private:
        std::vector<GameObject *> GameObjects;
    public:
        void addGameObject(GameObject *GameObject);

        void loadGameObjects();

        std::vector<GameObject *> *getGameObjects();
    };
}

#endif //BOMBERMAN_SCENE_HPP
