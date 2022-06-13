/*
** EPITECH PROJECT, 2022
** GameObject.hpp
** File description:
** TODO
*/

#pragma once

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
                : GameObject(modelPath, MyVector3{0, 0, 0}, 1.0f, WHITE) {
        };

        GameObject(const std::string &modelPath,
                   MyVector3 position,
                   float scale,
                   MyColor tint);

        ~GameObject() override;

        virtual void Draw();

        virtual void Update() {
        };

        virtual void Reset();

        void ResetPosition();

        void ResetRotation();

        void ResetScale();

        void ResetTint();

        void SetPosition(MyVector3 newPosition);

        virtual void SetActive(bool activate);

        virtual void Move(MyVector3 velocity);

        void SetRotation(MyVector3 newRotation);

        void SetScale(float newScale);

        bool GetActive() const;

        MyVector3 GetPosition(bool rounded = false);
    };

    class AnimatedGameObject : public GameObject {
    private:
        Texture2D texture{};
        bool hasTexture{};
        unsigned int animationNb;
        ModelAnimation *animations{};
        int animationSelected{};
        int animationFrame{};
        float tick{};
    public:
        AnimatedGameObject(const std::string &modelPath,
                           const std::string &texturePath,
                           const std::string &animationPath,
                           unsigned int animationCount,
                           float scale = 1.0f,
                           bool hasTexture = true);

        AnimatedGameObject(const std::string &modelPath,
                           unsigned int animationCount,
                           float scale = 1.0f)
                : AnimatedGameObject(modelPath, "", modelPath, animationCount, scale, false) {
        }

        ~AnimatedGameObject() override;

        void Update() override;

        void Reset() override;

        void ResetAnimation();

        void SetAnimation(int newSelectedAnimation);

        void NextFrame();

        void Move(MyVector3 velocity) override;
    };
}
