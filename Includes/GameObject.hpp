/*
** EPITECH PROJECT, 2022
** GameObject.hpp
** File description:
** TODO
*/

#pragma once

#include <cmath>
#include <vector>
#include "IObject.hpp"
#include "Objects.hpp"
#include "Color.hpp"

namespace bomberman {
    class StaticGameObject : public IObject {
    protected:
        Model model{};
        MyVector3 position;
    private:
        MyVector3 startPosition;
        float scale;
        float startScale;
        MyColor tint;
        MyColor startTint;
        bool active;
    public:
        explicit StaticGameObject(const std::string &modelPath)
                : StaticGameObject(modelPath, MyVector3{0, 0, 0}, 1, WHITE) {
        };

        StaticGameObject(const std::string &modelPath, MyVector3 position, float scale, MyColor tint);

        ~StaticGameObject() override;

        void Draw() override;

        void Update() override {}

        void Reset() override;

        void ResetPosition();

        void ResetScale();

        void ResetTint();

        void SetPosition(MyVector3 newPosition) override;

        void SetAnimation(int newSelectedAnimation) override {
            (void) newSelectedAnimation;
        }

        void SetActive(bool activate) override;

        void Move(MyVector3 velocity) override;
    };

    class AnimatedGameObject : public StaticGameObject {
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
        void SetAnimation(int newSelectedAnimation) override;
    };
}
