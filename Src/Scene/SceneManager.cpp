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
        CreateUiScene();
        CreateSettingsScene();
        CreateHowToPlayScene();
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

        menu->AddEntity(new GameCamera(MyVector3{0.0f, 22.0f, -12.0f},
                                        MyVector3{0.0f, 0.0f, 0.0f},
                                        MyVector3{0.0f, 1.0f, 0.0f},
                                        50.0f,
                                        CAMERA_PERSPECTIVE));
        menu->AddEntity(new GameObject("../Assets/Level/forest.obj"));
        menu->AddEntity(new GameSound("../Assets/Songs/ForestSong.mp3", true));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Fox.iqm",
                                       "../Assets/AnimalsCharacters/TexFox.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Pig.iqm",
                                       "../Assets/AnimalsCharacters/TexPig.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Pigeon.iqm",
                                       "../Assets/AnimalsCharacters/TexPigeon.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Toucan.iqm",
                                       "../Assets/AnimalsCharacters/TexToucan.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Fox.iqm",
                                       "../Assets/AnimalsCharacters/TexWolf.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Cat.iqm",
                                       "../Assets/AnimalsCharacters/TexCat.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Owl.iqm",
                                       "../Assets/AnimalsCharacters/TexOwl.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Gazelle.iqm",
                                       "../Assets/AnimalsCharacters/TexGazelle.png",
                                       "../Assets/AnimalsCharacters/Gazelle.iqm",
                                       0.1f));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Forest Bomberman", 525, 100, 200, WHITE));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Press Enter To Play", 625, 400, 125, WHITE, true));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Select players", 645, 100, 200, WHITE));
        menu->AddEntity(new GameButton(1750, 900, "../Assets/Buttons/howtoplay.png"));
        menu->AddEntity(new GameButton(50, 50, "../Assets/Buttons/darkmode.png", "../Assets/Buttons/lightmode.png"));
        menu->AddEntity(new GameButton(450, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->AddEntity(new GameButton(800, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->AddEntity(new GameButton(1400, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->AddEntity(new GameButton(1700, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->AddEntity(new GameButton(250, 875, "../Assets/Buttons/p1.png", "../Assets/Buttons/cpu.png", BUTTON_AI));
        menu->GetButtons().back()->SetState(true);
        menu->AddEntity(new GameButton(600, 875, "../Assets/Buttons/p2.png", "../Assets/Buttons/cpu.png", BUTTON_AI));
        menu->AddEntity(new GameButton(550, 300, "../Assets/Buttons/newgame.png", BUTTON_LOAD));
        menu->AddEntity(new GameButton(550, 550, "../Assets/Buttons/load.png", BUTTON_LOAD));
        menu->AddEntity(new GameButton(1200, 875, "../Assets/Buttons/p2.png", "../Assets/Buttons/cpu.png", BUTTON_AI));
        menu->AddEntity(new GameButton(1500, 875, "../Assets/Buttons/p2.png", "../Assets/Buttons/cpu.png", BUTTON_AI));
        
        menu->GetText(2)->SetActive(false);
        menu->AddEntity(new GameScript(gameRef, 1));
        menu->StartScene();
        scenes.push_back(menu);
    }

    void SceneManager::CreateLevelScene() {
        auto *level = new Scene;
        level->AddEntity(new GameCamera(MyVector3{0.0f, 22.0f, -12.0f},
                                       MyVector3{0.0f, 0.0f, 0.0f},
                                       MyVector3{0.0f, 1.0f, 0.0f},
                                       50.0f,
                                       CAMERA_PERSPECTIVE));
        auto *forest = new GameObject("../Assets/Level/forest.obj");
        forest->SetScale(50.f);
        forest->SetPosition(MyVector3{35.f, .0f, 30.f});
        level->AddEntity(forest);
        level->AddEntity(new GameSound("../Assets/Songs/CoffeeSong.mp3", true));
        level->AddEntity(new GameDrawMap("../Assets/Texture/brick.png", "../Assets/Texture/wood.png", WHITE));
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Forest Bomberman", 710, 30, 125, WHITE));
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Player 1", 60, 150, 80, WHITE));
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Player 2", 60, 770, 80, WHITE));
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Player 3", 1690, 150, 80, WHITE));
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Player 4", 1690, 770, 80, WHITE));
        level->AddEntity(new GameImage("../Assets/Heart/little_life.png", 75, 220));
        level->AddEntity(new GameImage("../Assets/Heart/little_life.png", 75, 840));
        level->AddEntity(new GameImage("../Assets/Heart/little_life.png", 1710, 220));
        level->AddEntity(new GameImage("../Assets/Heart/little_life.png", 1710, 840));
        level->AddEntity(new GameButton(50, 50, "../Assets/Buttons/return.png"));
        level->AddEntity(new GameScript(gameRef, 4));
        scenes.push_back(level);
    }

    void SceneManager::CreateUiScene() {
        auto *ui = new Scene;
        ui->AddEntity(new GameButton(1750, 50, "../Assets/Buttons/settings.png"));
        scenes.push_back(ui);
    }

    void SceneManager::CreateSettingsScene() {
        auto *settings = new Scene;
        settings->AddEntity(new GameImage("../Assets/UI/text_box.png", 500, 200));
        settings->AddEntity(new GameButton(1220, 770, "../Assets/UI/close_button90.png"));
        scenes.push_back(settings);
    }

    void SceneManager::CreateHowToPlayScene() {
        auto *howToPlay = new Scene;
        howToPlay->AddEntity(new GameImage("../Assets/UI/how_to_play.png", 550, 280));
        howToPlay->AddEntity(new GameButton(1220, 770, "../Assets/UI/close_button90.png"));
        scenes.push_back(howToPlay);
    }

    Scene *SceneManager::GetScene(int sceneId) {
        return scenes.at(sceneId);
    }
}
