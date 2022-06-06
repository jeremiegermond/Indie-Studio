/*
** EPITECH PROJECT, 2022
** SceneManager.cpp
** File description:
** TODO
*/

#include "SceneManager.hpp"
#include "Game.hpp"

namespace bomberman {
    void SceneManager::LoadScenes(Game *game) {
        gameRef = game;
        CreateMenuScene();
        CreateLevelScene();
    }

    void SceneManager::CreateMenuScene() {
        auto *menu = new Scene;
        menu->AddEntity(new GameCamera());
        menu->AddEntity(new GameObject("../Assets/Level/forest.obj"));
        menu->AddEntity(new GameSound("../Assets/Songs/ForestSong.mp3"));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Fox.iqm",
                                       "../Assets/AnimalsCharacters/TexFox.png",
                                       "../Assets/AnimalsCharacters/Fox.iqm",
                                       0));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Pig.iqm",
                                       "../Assets/AnimalsCharacters/TexPig.png",
                                       "../Assets/AnimalsCharacters/Pig.iqm",
                                       0));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Pigeon.iqm",
                                       "../Assets/AnimalsCharacters/TexPigeon.png",
                                       "../Assets/AnimalsCharacters/Pigeon.iqm",
                                       0));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Toucan.iqm",
                                       "../Assets/AnimalsCharacters/TexToucan.png",
                                       "../Assets/AnimalsCharacters/Toucan.iqm",
                                       0));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Wolf.iqm",
                                       "../Assets/AnimalsCharacters/TexWolf.png",
                                       "../Assets/AnimalsCharacters/Wolf.iqm",
                                       0));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Owl.iqm",
                                       "../Assets/AnimalsCharacters/TexOwl.png",
                                       "../Assets/AnimalsCharacters/Owl.iqm",
                                       0));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Gazelle.iqm",
                                       "../Assets/AnimalsCharacters/TexGazelle.png",
                                       "../Assets/AnimalsCharacters/Gazelle.iqm",
                                       0));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Forest Bomberman", 525, 100, 200, WHITE));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Press Enter To Play", 625, 400, 125, WHITE, true));
        menu->AddEntity(new GameScript(gameRef, 1));
        menu->StartScene();
        scenes.push_back(menu);
    }

    void SceneManager::CreateLevelScene() {
        auto *level = new Scene;
        level->AddEntity(new GameCamera());
        level->AddEntity(new AnimatedGameObject("../Assets/model.iqm",
                                               "../Assets/txr_model.png",
                                               "../Assets/model.iqm",
                                               0));
        level->AddEntity(new GameSound("../Assets/Songs/CoffeeSong.mp3"));
        scenes.push_back(level);
    }

    Scene *SceneManager::GetScene(int sceneId) {
        return scenes.at(sceneId);
    }
}
