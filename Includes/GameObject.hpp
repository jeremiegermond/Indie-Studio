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
#include "IObject.hpp"

namespace bomberman {
    class StaticGameObject : public IObject{
    private:
        Model model{};
        Vector3 position{};
        float scale{};
        Color tint{};
        bool active{};
    public:
        explicit StaticGameObject(const std::string& modelPath);
        ~StaticGameObject() override;
        void Draw() override;
        void Update() override {};
        void SetPosition(Vector3 newPosition) override;
        void SetAnimation(int newSelectedAnimation) override {
            (void) newSelectedAnimation;
        }
        void SetActive(bool activate) override;
        void Move(Vector3 velocity) override;
    };

    class AnimatedGameObject : public IObject{
    private:
        Model model{};
        Vector3 position{};
        float scale{};
        Color tint{};
        bool active{};
        Texture2D texture{};
        ModelAnimation *animations{};
        unsigned int animationNb;
        int animationFrame{};
        int animationSelected{};
    public:
        AnimatedGameObject(const std::string& modelPath,
                           const std::string& texturePath,
                           const std::string& animationPath,
                           unsigned int animationCount);
        ~AnimatedGameObject() override;
        void Draw() override;
        void Update() override;
        void SetPosition(Vector3 newPosition) override;
        void SetAnimation(int newSelectedAnimation) override;
        void SetActive(bool activate) override;
        void Move(Vector3 velocity) override;
    };
}

#endif //BOMBERMAN_GAMEOBJECT_HPP
