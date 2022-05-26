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
#include "GameCamera.hpp"
#include "GameSound.hpp"


namespace bomberman {
    class Scene {
    private:
        std::vector<IObject *> GameObjects;
        std::vector<GameSound *> GameSounds;
        std::vector<GameCamera *> GameCameras;
// std::vector<Camera> GameCameras;
// std::vector<Shader> GameShaders;
    public:
        Scene() = default;

        virtual ~Scene() = default;

        void AddEntity(IEntity *entity);

        void StartScene();

        void DrawScene();
    };
}

#endif //BOMBERMAN_SCENE_HPP
