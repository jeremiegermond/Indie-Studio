/*
** EPITECH PROJECT, 2022
** GameObject.cpp
** File description:
** TODO
*/

#include "GameObject.hpp"

namespace bomberman {
    StaticGameObject::StaticGameObject(const std::string &modelPath,
                                       Vector3 position,
                                       float scale,
                                       Color tint)
            : position(position),
              startPosition(position),
              scale(scale),
              startScale(scale),
              tint(tint),
              startTint(tint),
              active(true) {

        model = LoadModel(modelPath.c_str());
    };

    StaticGameObject::~StaticGameObject() {
        UnloadModel(model);
    }

    void StaticGameObject::Draw() {
        if (active)
            DrawModel(model, position, scale, tint);
    }

    void StaticGameObject::Reset() {
        ResetPosition();
        ResetScale();
        ResetTint();
        SetActive(true);
    }

    void StaticGameObject::ResetPosition() {
        SetPosition(startPosition);
    }

    void StaticGameObject::ResetScale() {
        scale = startScale;
    }

    void StaticGameObject::ResetTint() {
        tint = startTint;
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

    AnimatedGameObject::AnimatedGameObject(const std::string &modelPath,
                                           const std::string &texturePath,
                                           const std::string &animationPath,
                                           unsigned int animationCount)
            : StaticGameObject(modelPath), animationNb(animationCount) {
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

    void AnimatedGameObject::Update() {
        UpdateModelAnimation(model, animations[animationSelected], animationFrame);
        animationFrame++;
        if (animationFrame >= animations[animationSelected].frameCount)
            animationFrame = 0;
    }

    void AnimatedGameObject::Reset() {
        ResetPosition();
        ResetScale();
        ResetTint();
        ResetAnimation();
        SetActive(true);
    }

    void AnimatedGameObject::ResetAnimation() {
        animationFrame = 0;
    }

    void AnimatedGameObject::SetAnimation(int newSelectedAnimation) {
        animationSelected = newSelectedAnimation;
        animationFrame = 0;
    }
}
