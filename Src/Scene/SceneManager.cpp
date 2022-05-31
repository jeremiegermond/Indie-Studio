/*
** EPITECH PROJECT, 2022
** SceneManager.cpp
** File description:
** TODO
*/

#include "SceneManager.hpp"

namespace bomberman {
    void SceneManager::LoadScenes(Game *game) {
        gameRef = game;
        CreateMenuScene();
        CreateLevelScene();
    }

    void SceneManager::CreateMenuScene() {
        Scene menu;
        menu.AddEntity(new GameCamera());
        menu.AddEntity(new StaticGameObject("../Assets/Level/forest.obj"));
        menu.AddEntity(new StaticGameObject("../Assets/Level/leafs.obj"));
        menu.AddEntity(new GameSound("../Assets/Songs/ForestSong.mp3"));
        menu.AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Forest Bomberman", 525, 100, 200, WHITE));
        menu.AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Press Enter To Play", 625, 400, 125, WHITE, true));
        menu.AddEntity(new GameScript(gameRef, 1));
        scenes.push_back(menu);
    }

    void SceneManager::CreateLevelScene() {
        Scene level;
        level.AddEntity(new GameCamera());
        level.AddEntity(new AnimatedGameObject("../Assets/model.iqm",
                                               "../Assets/txr_model.png",
                                               "../Assets/model.iqm",
                                               0));
        scenes.push_back(level);
    }

    Scene SceneManager::GetScene(int sceneId) {
        return scenes.at(sceneId);
    }
}
