/*
** EPITECH PROJECT, 2022
** SceneManager.cpp
** File description:
** TODO
*/

#include "SceneManager.hpp"
#include "Game.hpp"

namespace bomberman {
    SceneManager::SceneManager(Game *pGame) {
        gameRef = pGame;
        CreateMenuScene();
        CreateLevelScene();
    }

    void SceneManager::CreateMenuScene() {
        auto *menu = new Scene;
        menu->AddEntity(new GameCamera());
        menu->GetCamera(0)->SetMode(CAMERA_ORBITAL);
        menu->AddEntity(new GameCamera(MyVector3{-1.7f, 0.5f, -1.1f},
                                       MyVector3{0.0f, 0.0f, 0.0f},
                                       MyVector3{0.0f, 1.0f, 0.0f},
                                       32.0f,
                                       CAMERA_PERSPECTIVE));
        menu->AddEntity(new GameObject("../Assets/Level/forest.obj"));
        menu->AddEntity(new GameSound("../Assets/Songs/ForestSong.mp3"));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Fox.iqm",
                                       "../Assets/AnimalsCharacters/TexFox.png",
                                       "../Assets/AnimalsCharacters/Fox.iqm",
                                       0, 0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Pig.iqm",
                                       "../Assets/AnimalsCharacters/TexPig.png",
                                       "../Assets/AnimalsCharacters/Pig.iqm",
                                       0, 0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Pigeon.iqm",
                                       "../Assets/AnimalsCharacters/TexPigeon.png",
                                       "../Assets/AnimalsCharacters/Pigeon.iqm",
                                       0, 0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Toucan.iqm",
                                       "../Assets/AnimalsCharacters/TexToucan.png",
                                       "../Assets/AnimalsCharacters/Toucan.iqm",
                                       0, 0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Wolf.iqm",
                                       "../Assets/AnimalsCharacters/TexWolf.png",
                                       "../Assets/AnimalsCharacters/Wolf.iqm",
                                       0, 0.05f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Owl.iqm",
                                       "../Assets/AnimalsCharacters/TexOwl.png",
                                       "../Assets/AnimalsCharacters/Owl.iqm",
                                       0, 0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Gazelle.iqm",
                                       "../Assets/AnimalsCharacters/TexGazelle.png",
                                       "../Assets/AnimalsCharacters/Gazelle.iqm",
                                       0, 0.1f));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Forest Bomberman", 525, 100, 200, WHITE));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Press Enter To Play", 625, 400, 125, WHITE, true));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Select players", 625, 100, 200, WHITE));
        menu->GetText(2)->SetActive(false);
        menu->AddEntity(new GameScript(gameRef, 1));
        menu->StartScene();
        scenes.push_back(menu);
    }

    void SceneManager::CreateLevelScene() {
        auto *level = new Scene;
        level->AddEntity(new GameCamera());
        level->AddEntity(new GameObject("../Assets/Level/forest.obj"));
        level->AddEntity(new GameSound("../Assets/Songs/CoffeeSong.mp3"));
        level->AddEntity(new GameDrawMap({ 0.0f, 0.0f, 0.0f }, BROWN));
        scenes.push_back(level);
    }

    Scene *SceneManager::GetScene(int sceneId) {
        return scenes.at(sceneId);
    }
}
