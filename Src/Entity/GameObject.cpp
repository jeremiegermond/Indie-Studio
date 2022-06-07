/*
** EPITECH PROJECT, 2022
** GameObject.cpp
** File description:
** TODO
*/

#include "GameObject.hpp"

namespace bomberman {
    GameObject::GameObject(const std::string &modelPath,
                           MyVector3 position,
                           float scale,
                           MyColor tint)
            : position(position),
              rotation(MyVector3 {0.0f, 0.0f, 0.0f}),
              startPosition(position),
              startRotation(rotation),
              scale(scale),
              startScale(scale),
              tint(tint),
              startTint(tint),
              active(true) {

        model = LoadModel(modelPath.c_str());
    };

    GameObject::~GameObject() {
        UnloadModel(model);
    }

    void GameObject::Draw() {
        if (active) {
            // DrawModel(model, position, scale, tint);
            model.transform = MatrixRotateXYZ(rotation);
            DrawModelEx(model, position, MyVector3{1.0f, 0.0f, 0.0f}, -90.0f, MyVector3{scale, scale, scale}, tint);
        }
    }

    void GameObject::Reset() {
        ResetPosition();
        ResetRotation();
        ResetScale();
        ResetTint();
        SetActive(true);
    }

    void GameObject::ResetPosition() {
        SetPosition(startPosition);
    }

    void GameObject::ResetRotation() {
        rotation = startRotation;
    }

    void GameObject::ResetScale() {
        scale = startScale;
    }

    void GameObject::ResetTint() {
        tint = startTint;
    }

    void GameObject::SetPosition(MyVector3 newPosition) {
        position = newPosition;
    }

    void GameObject::SetActive(bool activate) {
        active = activate;
    }

    void GameObject::Move(MyVector3 velocity) {
        position.x += velocity.x * GetFrameTime();
        position.y += velocity.y * GetFrameTime();
        position.z += velocity.z * GetFrameTime();
    }

    AnimatedGameObject::AnimatedGameObject(const std::string &modelPath,
                                           const std::string &texturePath,
                                           const std::string &animationPath,
                                           unsigned int animationCount,
                                           float scale)
            : GameObject(modelPath, MyVector3{0, 0, 0}, scale, WHITE), animationNb(animationCount) {
        texture = LoadTexture(texturePath.c_str());
        SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
        animations = LoadModelAnimations(animationPath.c_str(), &animationNb);
    }

    AnimatedGameObject::~AnimatedGameObject() {
        std::cout << "Unloading model" << std::endl;
        for (unsigned int i = 0; i < animationNb; i++)
            UnloadModelAnimation(animations[i]);
        RL_FREE(animations);
        UnloadTexture(texture);
        UnloadModel(model);
    }

    void AnimatedGameObject::Update() {
        UpdateModelAnimation(model, animations[animationSelected], animationFrame);
        if (IsKeyDown(KEY_A)) {
            Move(MyVector3 {1.0f, 0.0f, 0.0f});
            rotation.z = -1.5;
            animationFrame++;
        } else if (IsKeyDown(KEY_D)) {
            Move(MyVector3 {-1.0f, 0.0f, 0.0f});
            rotation.z = 1.5;
            animationFrame++;
        } else if (IsKeyDown(KEY_W)) {
            Move(MyVector3 {0.0f, 0.0f, 1.0f});
            rotation.z = 0;
            animationFrame++;
        } else if (IsKeyDown(KEY_S)) {
            Move(MyVector3 {0.0f, 0.0f, -1.0f});
            rotation.z = 3;
            animationFrame++;
        } else if (animationFrame)
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
