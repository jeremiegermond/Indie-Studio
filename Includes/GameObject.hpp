/*
** EPITECH PROJECT, 2022
** GameObject.hpp
** File description:
** TODO
*/

#pragma once

#include <cmath>
#include <vector>
#include "Objects.hpp"
#include "Color.hpp"
#include "IEntity.hpp"

namespace bomberman {
    class GameObject : public IEntity {
    protected:
        Model model{};
        MyVector3 position;
        MyVector3 rotation;
    private:
        MyVector3 startPosition;
        MyVector3 startRotation;
        float scale;
        float startScale;
        MyColor tint;
        MyColor startTint;
        bool active;
    public:
        explicit GameObject(const std::string &modelPath)
                : GameObject(modelPath, MyVector3{0, 0, 0}, 1, WHITE) {
        };

        GameObject(const std::string &modelPath,
                   MyVector3 position,
                   float scale,
                   MyColor tint);

        ~GameObject() override;

        void Draw();
        virtual void Update() {};
        virtual void Reset();
        void ResetPosition();
        void ResetRotation();
        void ResetScale();
        void ResetTint();
        void SetPosition(MyVector3 newPosition);
        void SetActive(bool activate);
        void Move(MyVector3 velocity);
    };

    class AnimatedGameObject : public GameObject {
    private:
        Texture2D texture{};
        ModelAnimation *animations{};
        unsigned int animationNb;
        int animationFrame{};
        int animationSelected{};

    public:
        AnimatedGameObject(const std::string &modelPath, const std::string &texturePath, const std::string &animationPath, unsigned int animationCount);
        ~AnimatedGameObject() override;

        void Update() override;
        void Reset() override;
        void ResetAnimation();

        void SetAnimation(int newSelectedAnimation);
    };
}
