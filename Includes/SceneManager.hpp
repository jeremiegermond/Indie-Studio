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
        GameLoading *loading;

    public:
        SceneManager() = default;
        explicit SceneManager(Game *pGame);

        virtual ~SceneManager() = default;

        void CreateMenuScene();

        void CreateLevelScene();

        Scene *GetScene(int sceneId);

        void CreateUiScene();

        void CreateSettingsScene();

        void CreateHowToPlayScene();
    
        void display_loading(int percentage) {
            loading->UpdateAndDraw(percentage);
        }
    };
}

#endif //BOMBERMAN_SCENEMANAGER_HPP
