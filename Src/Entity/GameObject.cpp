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
              rotation(MyVector3{0.0f, 0.0f, 0.0f}),
              startPosition(position),
              startRotation(rotation),
              scale(scale),
              startScale(scale),
              tint(tint),
              startTint(tint),
              active(true) {

        if (!std::ifstream(modelPath).good())
            throw BuildError("Failed to load model " + modelPath, __FILE__, __LINE__);
        model = Load::loadModel(modelPath.c_str());
    };

    GameObject::~GameObject() {
        UnloadModel(model);
    }

    void GameObject::Draw() {
        if (active) {
            model.transform = MatrixRotateXYZ(rotation);
            DrawModelEx(model,
                        position,
                        MyVector3{1.0f, 0.0f, 0.0f},
                        -90.0f,
                        MyVector3{scale, scale, scale},
                        tint);
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

    void GameObject::SetScale(float newScale) {
        scale = newScale;
    }

    bool GameObject::GetActive() const {
        return active;
    }

    MyVector3 GameObject::GetPosition(bool rounded) {
        MyVector3 currentPos = position;
        if (rounded) {
            currentPos.x = round(currentPos.x);
            currentPos.z = round(currentPos.z);
        }
        return currentPos;
    }

    AnimatedGameObject::AnimatedGameObject(const std::string &modelPath,
                                           const std::string &texturePath,
                                           const std::string &animationPath,
                                           unsigned int animationCount,
                                           float scale,
                                           bool hasTexture)
            : GameObject(modelPath, MyVector3{0, 0, 0}, scale, WHITE),
              hasTexture(hasTexture),
              animationNb(animationCount) {
        tick = .0f;
        if (hasTexture) {
            texture = LoadTexture(texturePath.c_str());
            SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
        }
        animations = LoadModelAnimations(animationPath.c_str(), &animationNb);
    }

    AnimatedGameObject::~AnimatedGameObject() {
        std::cout << "Unloading model" << std::endl;
        for (unsigned int i = 0; i < animationNb; i++)
            UnloadModelAnimation(animations[i]);
        RL_FREE(animations);
        if (hasTexture)
            UnloadTexture(texture);
        UnloadModel(model);
    }

    void AnimatedGameObject::Update() {
        NextFrame();
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
        if (animationSelected == newSelectedAnimation)
            return;
        animationSelected = newSelectedAnimation;
        ResetAnimation();
    }

    void AnimatedGameObject::NextFrame() {
        UpdateModelAnimation(model, animations[animationSelected], animationFrame);
        tick += 24.0f * GetFrameTime();
        animationFrame = int(round(tick));
        if (animationFrame >= animations[animationSelected].frameCount)
            ResetAnimation();
    }

    void AnimatedGameObject::Move(MyVector3 velocity) {
        if (animationSelected)
            SetAnimation(0);
        GameObject::Move(velocity);
    }
}
