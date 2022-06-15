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
        loading = new GameLoading();
        display_loading(5);
        tree = new GameObject("../Assets/Level/forest.obj");
        CreateMenuScene();
        display_loading(70);
        CreateLevelScene();
        display_loading(90);
        CreateUiScene();
        display_loading(95);
        CreateSettingsScene();
        display_loading(98);
        CreateHowToPlayScene();
        display_loading(99);
        CreateVictoryOrDefeatScene();
        display_loading(100);
        CreateTieScene();
        scenes.front()->StartScene();
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
        menu->AddEntity(tree);
        display_loading(8);
        menu->AddEntity(new GameSound("../Assets/Songs/ForestSong.mp3", true));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Fox.iqm",
                                       "../Assets/AnimalsCharacters/TexFox.png",
                                       0.1f));
        display_loading(10);
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Pig.iqm",
                                       "../Assets/AnimalsCharacters/TexPig.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Pigeon.iqm",
                                       "../Assets/AnimalsCharacters/TexPigeon.png",
                                       0.1f));
        display_loading(13);
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Toucan.iqm",
                                       "../Assets/AnimalsCharacters/TexToucan.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Fox.iqm",
                                       "../Assets/AnimalsCharacters/TexWolf.png",
                                       0.1f));
        display_loading(15);
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Cat.iqm",
                                       "../Assets/AnimalsCharacters/TexCat.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Owl.iqm",
                                       "../Assets/AnimalsCharacters/TexOwl.png",
                                       0.1f));
        display_loading(20);
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Gazelle.iqm",
                                       "../Assets/AnimalsCharacters/TexGazelle.png",
                                       "../Assets/AnimalsCharacters/Gazelle.iqm",
                                       0.1f));
        display_loading(30);
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Forest Bomberman", 525, 100, 200, WHITE));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Press Enter To Play", 625, 400, 125, WHITE, true));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Select players", 645, 100, 200, WHITE));
        menu->AddEntity(new GameButton(1750, 900, "../Assets/Buttons/howtoplay.png"));
        menu->AddEntity(new GameButton(50, 50, "../Assets/Buttons/darkmode.png", "../Assets/Buttons/lightmode.png"));
        display_loading(40);
        menu->AddEntity(new GameButton(450, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->AddEntity(new GameButton(800, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->AddEntity(new GameButton(1400, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->AddEntity(new GameButton(1700, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        display_loading(50);
        menu->AddEntity(new GameButton(250, 875, "../Assets/Buttons/p1.png", "../Assets/Buttons/cpu.png", BUTTON_AI));
        menu->GetButtons().back()->SetState(true);
        menu->AddEntity(new GameButton(600, 875, "../Assets/Buttons/p2.png", "../Assets/Buttons/cpu.png", BUTTON_AI));
        menu->AddEntity(new GameButton(550, 300, "../Assets/Buttons/newgame.png", BUTTON_LOAD));
        menu->AddEntity(new GameButton(550, 550, "../Assets/Buttons/load.png", BUTTON_LOAD));
        menu->AddEntity(new GameButton(1200, 875, "../Assets/Buttons/p3.png", "../Assets/Buttons/cpu.png", BUTTON_AI));
        menu->AddEntity(new GameButton(1500, 875, "../Assets/Buttons/p4.png", "../Assets/Buttons/cpu.png", BUTTON_AI));
        auto *bomb = new AnimatedGameObject("../Assets/Level/bomb.iqm",
                                            "../Assets/Level/bomb.png",
                                            "../Assets/Level/bomb.iqm",
                                            0,
                                            1.5f);
        bomb->SetPosition(MyVector3{.6f, .0f, .6f});
        bomb->SetRotation(MyVector3{0.f, 0.f, 2.3f});
        menu->AddEntity(bomb);
        display_loading(60);
        menu->GetText(2)->SetActive(false);
        menu->AddEntity(new GameScript(gameRef, 1));
        scenes.push_back(menu);
    }

    void SceneManager::CreateLevelScene() {
        auto *level = new Scene;
        level->AddEntity(new GameCamera(MyVector3{0.0f, 22.0f, -12.0f},
                                       MyVector3{0.0f, 0.0f, 0.0f},
                                       MyVector3{0.0f, 1.0f, 0.0f},
                                       50.0f,
                                       CAMERA_PERSPECTIVE));
        display_loading(75);
        level->AddEntity(tree);
        level->AddEntity(new GameSound("../Assets/Songs/CoffeeSong.mp3", true));
        level->AddEntity(new GameDrawMap("../Assets/Texture/brick.png", "../Assets/Texture/wood.png", WHITE));
        display_loading(80);
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Forest Bomberman", 710, 30, 125, WHITE));
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Player 1", 145, 150, 80, WHITE));
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Player 2", 145, 550, 80, WHITE));
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Player 3", 1605, 150, 80, WHITE));
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Player 4", 1605, 550, 80, WHITE));
        display_loading(85);
        level->AddEntity(new GameImage("../Assets/Heart/little_life.png", 160, 220));
        level->AddEntity(new GameImage("../Assets/Heart/little_life.png", 160, 620));
        level->AddEntity(new GameImage("../Assets/Heart/little_life.png", 1625, 220));
        level->AddEntity(new GameImage("../Assets/Heart/little_life.png", 1625, 620));
        for (int y = 0; y < 2; y++) {
            level->AddEntity(new GameImage("../Assets/PowerUps/background3.png", 40, 320 + 400 * y));
            level->AddEntity(new GameImage("../Assets/PowerUps/bomb.png", 80, 345 + 400 * y));
            level->AddEntity(new GameImage("../Assets/PowerUps/speed.png", 270, 345 + 400 * y));
            level->AddEntity(new GameImage("../Assets/PowerUps/fireUp.png", 60, 430 + 400 * y));
            level->AddEntity(new GameImage("../Assets/PowerUps/wall.png", 230, 425 + 400 * y));

            level->AddEntity(new GameImage("../Assets/PowerUps/background3.png", 1500, 320 + 400 * y));
            level->AddEntity(new GameImage("../Assets/PowerUps/bomb.png", 1545, 345 + 400 * y));
            level->AddEntity(new GameImage("../Assets/PowerUps/speed.png", 1725, 345 + 400 * y));
            level->AddEntity(new GameImage("../Assets/PowerUps/fireUp.png", 1530, 430 + 400 * y));
            level->AddEntity(new GameImage("../Assets/PowerUps/wall.png", 1695, 425 + 400 * y));
        }
        for (int i = 0; i < 4; i++) {
            level->AddEntity(new GamePowerUp());
        }
        level->AddEntity(new GameButton(50, 40, "../Assets/Buttons/home.png"));
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
        settings->AddEntity(new GameImage("../Assets/UI/text_box.png", 500, 150));
        settings->AddEntity(new GameButton(1220, 790, "../Assets/UI/close_button90.png"));
        settings->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Fullscreen", 815, 430, 90, BLACK));
        settings->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "  Music", 815, 580, 90, BLACK));
        settings->AddEntity(new GameButton(1040, 440, "../Assets/UI/checkbox_checked.png", "../Assets/UI/checkbox.png"));
        settings->AddEntity(new GameButton(1040, 590, "../Assets/UI/checkbox_checked.png", "../Assets/UI/checkbox.png"));
        settings->AddEntity(new GameScript(gameRef, 6));
        if (IsWindowFullscreen())
            settings->GetButton(1)->SetState(true);
        settings->GetButton(2)->SetState(true);
        scenes.push_back(settings);
    }

    void SceneManager::CreateHowToPlayScene() {
        auto *howToPlay = new Scene;
        howToPlay->AddEntity(new GameImage("../Assets/UI/how_to_play.png", 0, 0));
        howToPlay->AddEntity(new GameButton(1477, 900, "../Assets/UI/close_button90.png"));
        scenes.push_back(howToPlay);
    }

    void SceneManager::CreateVictoryOrDefeatScene() {
        auto *victoryOrDefeat = new Scene;
        victoryOrDefeat->AddEntity(tree);
        victoryOrDefeat->AddEntity(new GameCamera(MyVector3{-1.7f, 0.5f, -1.1f},
                                       MyVector3{0.0f, 0.0f, 0.0f},
                                       MyVector3{0.0f, 1.0f, 0.0f},
                                       20.0f,
                                       CAMERA_PERSPECTIVE));
        victoryOrDefeat->AddEntity(new GameSound("../Assets/Songs/Victory.mp3", true));
        victoryOrDefeat->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "WINNER !", 725, 700, 200, WHITE, true));
        victoryOrDefeat->AddEntity(new GameButton(50, 40, "../Assets/Buttons/home.png"));
        victoryOrDefeat->AddEntity(new GameScript(gameRef, 5));
        victoryOrDefeat->AddEntity(new ParticleSystem());
        scenes.push_back(victoryOrDefeat);
    }

    void SceneManager::CreateTieScene() {
        auto *tie = new Scene;
        tie->AddEntity(tree);
        tie->AddEntity(new GameCamera(MyVector3{-1.7f, 0.5f, -1.1f},
                                       MyVector3{0.0f, 0.0f, 0.0f},
                                       MyVector3{0.0f, 1.0f, 0.0f},
                                       25.0f,
                                       CAMERA_PERSPECTIVE));
        tie->AddEntity(new GameSound("../Assets/Songs/Tie.mp3", true));
        tie->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "TIE ...", 800, 100, 200, WHITE, true));
        tie->AddEntity(new GameButton(50, 40, "../Assets/Buttons/home.png"));
        tie->AddEntity(new GameScript(gameRef, 5));
        scenes.push_back(tie);
    }

    Scene *SceneManager::GetScene(int sceneId) {
        if (scenes.size() <= size_t(sceneId))
            return nullptr;
        return scenes.at(sceneId);
    }
}
