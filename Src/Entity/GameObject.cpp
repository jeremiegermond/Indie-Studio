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

    void GameObject::SetRotation(MyVector3 newRotation) {
        rotation = newRotation;
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
        tick = .0f;
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
        if (IsKeyDown(KEY_A)) {
            Move(MyVector3{1.0f, 0.0f, 0.0f});
            rotation.z = -1.5;
            NextFrame();
        } else if (IsKeyDown(KEY_D)) {
            Move(MyVector3{-1.0f, 0.0f, 0.0f});
            rotation.z = 1.5;
            NextFrame();
        } else if (IsKeyDown(KEY_W)) {
            Move(MyVector3{0.0f, 0.0f, 1.0f});
            rotation.z = 0;
            NextFrame();
        } else if (IsKeyDown(KEY_S)) {
            Move(MyVector3{0.0f, 0.0f, -1.0f});
            rotation.z = 3;
            NextFrame();
        } else if (animationNb > 1) {
            std::cout << animationNb <<std::endl;
            if (!animationSelected)
                SetAnimation(1);
            NextFrame();
        } else if (animationFrame) {
            NextFrame();
        }
        if (IsKeyDown(KEY_P))
            printf("Ppos: %f %f %f\n", position.x, position.y, position.z);
    }

    void AnimatedGameObject::Reset() {
        GameObject::Reset();
        ResetAnimation();
    }

    void AnimatedGameObject::ResetAnimation() {
        animationFrame = 0;
        tick = .0f;
    }

    void AnimatedGameObject::SetAnimation(int newSelectedAnimation) {
        animationSelected = newSelectedAnimation;
        ResetAnimation();
    }

    void AnimatedGameObject::NextFrame() {
        UpdateModelAnimation(model, animations[animationSelected], animationFrame);
        tick += 24.0f * GetFrameTime();
        animationFrame = int (round(tick));
        if (animationFrame >= animations[animationSelected].frameCount)
           ResetAnimation();
    }

    void AnimatedGameObject::Move(MyVector3 velocity) {
        if (animationSelected)
            SetAnimation(0);
        GameObject::Move(velocity);
    }
}
