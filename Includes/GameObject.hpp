/*
** EPITECH PROJECT, 2022
** GameObject.hpp
** File description:
** TODO
*/
#ifndef BOMBERMAN_GAMEOBJECT_HPP
#define BOMBERMAN_GAMEOBJECT_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include "raylib.h"

namespace bomberman {
    class GameObject {
    private:
        unsigned int count;
        int animFrameCounter;
        std::string model_path;
        std::string texture_path{};
        std::string anim_path{};
        Model model{};
        Texture2D texture{};
        ModelAnimation *animation{};
    public:
        GameObject(std::string modelPath, std::string texturePath, std::string animPath);
        explicit GameObject(std::string modelPath);
        ~GameObject();
        void load();
        void UpdateAnimation();
        void draw();
    };
}

#endif //BOMBERMAN_GAMEOBJECT_HPP
