/*
** EPITECH PROJECT, 2022
** GameObject.hpp
** File description:
** TODO
*/
#ifndef BOMBERMAN_GAMEOBJECT_HPP
#define BOMBERMAN_GAMEOBJECT_HPP

#pragma once
#include <cmath>
#include <vector>
#include "IObject.hpp"

namespace bomberman {
    class StaticGameObject : public IObject {
    protected:
        Model model{};
        Vector3 position;
    private:
        Vector3 startPosition;
        float scale;
        float startScale;
        Color tint;
        Color startTint;
        bool active;
    public:
        explicit StaticGameObject(const std::string &modelPath)
                : StaticGameObject(modelPath, Vector3{0, 0, 0}, 1, WHITE) {
        };

        StaticGameObject(const std::string &modelPath,
                         Vector3 position,
                         float scale,
                         Color tint);

        ~StaticGameObject() override;

        void Draw() override;

        void Update() override {
        };

        void Reset() override;

        void ResetPosition();

        void ResetScale();

        void ResetTint();

        void SetPosition(Vector3 newPosition) override;

        void SetAnimation(int newSelectedAnimation) override {
            (void) newSelectedAnimation;
        }

        void SetActive(bool activate) override;

        void Move(Vector3 velocity) override;
    };

    class AnimatedGameObject : public StaticGameObject {
    private:
        Texture2D texture{};
        ModelAnimation *animations{};
        unsigned int animationNb;
        int animationFrame{};
        int animationSelected{};
    public:
        AnimatedGameObject(const std::string &modelPath,
                           const std::string &texturePath,
                           const std::string &animationPath,
                           unsigned int animationCount);

        ~AnimatedGameObject() override;

        void Update() override;

        void Reset() override;

        void ResetAnimation();

        void SetAnimation(int newSelectedAnimation) override;
    };
}

#endif //BOMBERMAN_GAMEOBJECT_HPP
