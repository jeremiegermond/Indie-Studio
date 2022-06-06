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

#include "IEntity.hpp"

namespace bomberman {
    class GameObject : public IEntity {
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
        explicit GameObject(const std::string &modelPath)
                : GameObject(modelPath, Vector3{0, 0, 0}, 1, WHITE) {
        };

        GameObject(const std::string &modelPath,
                   Vector3 position,
                   float scale,
                   Color tint);

        ~GameObject() override;

        void Draw();

        virtual void Update() {};

        virtual void Reset();

        void ResetPosition();

        void ResetScale();

        void ResetTint();

        void SetPosition(Vector3 newPosition);

        void SetActive(bool activate);

        void Move(Vector3 velocity);
    };

    class AnimatedGameObject : public GameObject {
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

        void SetAnimation(int newSelectedAnimation);
    };
}

#endif //BOMBERMAN_GAMEOBJECT_HPP
