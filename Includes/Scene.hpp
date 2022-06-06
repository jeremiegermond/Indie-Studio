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
#include "GamePlayer.hpp"
#include "GameText.hpp"
#include "GameScript.hpp"

namespace bomberman {
    class Scene {
    private:
        std::vector<GamePlayer *> PlayerQueue;
        std::vector<GamePlayer *> Players;
        std::vector<GameObject *> GameObjects;
        std::vector<GameSound *> GameSounds;
        std::vector<GameCamera *> GameCameras;
        std::vector<GameText *> GameTexts;
        std::vector<GameScript *> GameScripts;
        // std::vector<Camera> GameCameras;
        // std::vector<Shader> GameShaders;
    public:
        Scene() = default;

        virtual ~Scene() = default;

        void AddEntity(IEntity *entity);

        void StartScene();

        void DrawScene();

        void UnloadScene();
    };
}

#endif //BOMBERMAN_SCENE_HPP
