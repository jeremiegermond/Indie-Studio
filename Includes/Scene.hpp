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
        std::vector<IObject *> GameObjects;
        std::vector<Sound> GameSounds;
// std::vector<Camera> GameCameras;
// std::vector<Shader> GameShaders;
    public:
        Scene() = default;

        virtual ~Scene() = default;

        void AddGameObject(IObject *GameObject);

        void AddSound(Sound sound);

        void StartScene();

        void DrawScene();
    };
}

#endif //BOMBERMAN_SCENE_HPP
