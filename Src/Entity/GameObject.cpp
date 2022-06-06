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
        position.x += velocity.x;
        position.y += velocity.y;
        position.z += velocity.z;
    }

    AnimatedGameObject::AnimatedGameObject(const std::string &modelPath,
                                           const std::string &texturePath,
                                           const std::string &animationPath,
                                           unsigned int animationCount)
            : GameObject(modelPath), animationNb(animationCount) {
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
            Move(MyVector3 {0.01f, 0.0f, 0.0f});
            rotation.z = -1.5;
            animationFrame++;
        } else if (IsKeyDown(KEY_D)) {
            Move(MyVector3 {-0.01f, 0.0f, 0.0f});
            rotation.z = 1.5;
            animationFrame++;
        } else if (IsKeyDown(KEY_W)) {
            Move(MyVector3 {0.0f, 0.0f, 0.01f});
            rotation.z = 0;
            animationFrame++;
        } else if (IsKeyDown(KEY_S)) {
            Move(MyVector3 {0.0f, 0.0f, -0.01f});
            rotation.z = 3;
            animationFrame++;
            }
        if (animationFrame >= animations[animationSelected].frameCount)
            animationFrame = 0;
        if (IsKeyDown(KEY_J))
            rotation.x += .01;
        if (IsKeyDown(KEY_K))
            rotation.x -= .01;
        if (IsKeyDown(KEY_N))
            rotation.z += .01;
        if (IsKeyDown(KEY_M))
            rotation.z -= .01;
        if (IsKeyDown(KEY_I))
            rotation.y += .01;
        if (IsKeyDown(KEY_O))
            rotation.y -= .01;
        if (IsKeyDown(KEY_R))
            ResetRotation();

        if (IsKeyPressed(KEY_P)) {
            std::cout << "Pos: " << position.x << "x " << position.y << "y " << position.z << "z" << std::endl;
            std::cout << "Rot: " << rotation.x << "x " << rotation.y << "y " << rotation.z << "z" << std::endl;
        }
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
