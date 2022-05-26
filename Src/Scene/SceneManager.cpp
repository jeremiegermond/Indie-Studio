/*
** EPITECH PROJECT, 2022
** SceneManager.cpp
** File description:
** TODO
*/

#include "SceneManager.hpp"

namespace bomberman {
    void SceneManager::LoadScenes() {
        CreateMenuScene();
        CreateLevelScene();
    }

    void SceneManager::CreateMenuScene() {
        Scene menu;
        menu.AddGameObject(new StaticGameObject("../Assets/Level/forest.obj"));
        menu.AddGameObject(new StaticGameObject("../Assets/Level/leafs.obj"));
        // Todo make sound object so it calls unload sound easily
        menu.AddSound(LoadSound("../Assets/Songs/ForestSong.mp3"));
        scenes.push_back(menu);
    }

    void SceneManager::CreateLevelScene() {
        Scene level;
        level.AddGameObject(new AnimatedGameObject("../Assets/model.iqm",
                                                   "../Assets/txr_model.png",
                                                   "../Assets/model.iqm", 0));
        scenes.push_back(level);
    }

    Scene SceneManager::GetScene(int sceneId) {
        return scenes.at(sceneId);
    }
}
