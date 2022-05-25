/*
** EPITECH PROJECT, 2022
** game.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_GAME_HPP
#define BOMBERMAN_GAME_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include "raylib.h"
#include "Map.hpp"

namespace bomberman {

    class Element {
    private:
        unsigned int count;
        int animFrameCounter;
        std::string model_path;
        std::string texture_path;
        std::string anim_path;
        Model model;
        Texture2D texture;
        ModelAnimation *animation;
    public:
        Element(std::string modelPath, std::string texturePath, std::string animPath);
        ~Element();
        void load();
        void UpdtModelAnim();
        void draw(RenderTexture2D *target, Camera3D *camera, Map *map);
    };

    class Scene {
    private:
        std::vector<Element *> elements;
    public:
        void addElement(Element *element);
        void loadElements();
        std::vector<Element *> *getElements();
    };

    class Game {
    private:
        int width;
        int height;
        float cam_angle;
        float cam_radius;

        Camera3D camera;
        Sound sound;

        std::vector<Scene *> scenes;

        Map map;
    public:
        Game();
        ~Game();

        void createWindow();
        Scene *createScene();
        Scene *getScene(int pos);
        void loadScene(){};

        void run();
    };

}


#endif //BOMBERMAN_GAME_HPP
