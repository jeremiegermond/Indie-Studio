/*
** EPITECH PROJECT, 2022
** GameObject.cpp
** File description:
** TODO
*/

#include "GameObject.hpp"

#include <utility>

namespace bomberman {
    StaticGameObject::StaticGameObject(const std::string& modelPath) {
        model = LoadModel(modelPath.c_str());
        position = Vector3 {0, 0, 0};
        scale = 1;
        tint = WHITE;
        active = true;
    }

    StaticGameObject::~StaticGameObject() {
        UnloadModel(model);
    }

    void StaticGameObject::Draw() {
        if (active)
            DrawModel(model, position, scale, tint);
    }

    void StaticGameObject::SetPosition(Vector3 newPosition) {
        position = newPosition;
    }

    void StaticGameObject::SetActive(bool activate) {
        active = activate;
    }

    void StaticGameObject::Move(Vector3 velocity) {
        position.x += velocity.x;
        position.y += velocity.y;
        position.z += velocity.z;
    }

    AnimatedGameObject::AnimatedGameObject(const std::string& modelPath,
                                           const std::string& texturePath,
                                           const std::string& animationPath,
                                           unsigned int animationCount) :
        animationNb(animationCount)
    {
        model = LoadModel(modelPath.c_str());
        position = Vector3 {0, 0, 0};
        scale = 1;
        tint = WHITE;
        active = true;
        texture = LoadTexture(texturePath.c_str());
        SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
        animations = LoadModelAnimations(animationPath.c_str(), &animationNb);
    }

    AnimatedGameObject::~AnimatedGameObject() {
        for (unsigned int i = 0; i < animationNb; i++)
            UnloadModelAnimation(animations[i]);
        RL_FREE(animations);
        UnloadTexture(texture);
        UnloadModel(model);
    }

    void AnimatedGameObject::Draw() {
        if (active)
            DrawModel(model, position, scale, tint);
    }

    void AnimatedGameObject::Update() {
        UpdateModelAnimation(model, animations[animationSelected], animationFrame);
        animationFrame++;
        if (animationFrame >= animations[animationSelected].frameCount)
            animationFrame = 0;
    }

    void AnimatedGameObject::SetPosition(Vector3 newPosition) {
        position = newPosition;
    }

    void AnimatedGameObject::SetAnimation(int newSelectedAnimation) {
        animationSelected = newSelectedAnimation;
        animationFrame = 0;
    }

    void AnimatedGameObject::SetActive(bool activate) {
        active = activate;
    }

    void AnimatedGameObject::Move(Vector3 velocity) {
        position.x += velocity.x;
        position.y += velocity.y;
        position.z += velocity.z;
    }
}
