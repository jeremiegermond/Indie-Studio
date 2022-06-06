/*
** EPITECH PROJECT, 2022
** GameObject.cpp
** File description:
** TODO
*/

#include "GameObject.hpp"

namespace bomberman {
    StaticGameObject::StaticGameObject(const std::string &modelPath,
                                       MyVector3 position,
                                       float scale,
                                       MyColor tint)
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
            // DrawModel(model, position, scale, tint);
            DrawModelEx(model, position, MyVector3{1.0f, 0.0f,0.0f}, -90.0f, MyVector3{scale, scale, scale}, tint);
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

    void StaticGameObject::SetPosition(MyVector3 newPosition) {
        position = newPosition;
    }

    void StaticGameObject::SetActive(bool activate) {
        active = activate;
    }

    void StaticGameObject::Move(MyVector3 velocity) {
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
        std::cout << "Unloading model" << std::endl;
        for (unsigned int i = 0; i < animationNb; i++)
            UnloadModelAnimation(animations[i]);
        RL_FREE(animations);
        UnloadTexture(texture);
        UnloadModel(model);
    }

    void AnimatedGameObject::Update() {
        UpdateModelAnimation(model, animations[animationSelected], animationFrame);
        if (IsKeyDown(KEY_SPACE))
            animationFrame++;
        if (animationFrame >= animations[animationSelected].frameCount)
            animationFrame = 0;
        if (IsKeyDown(KEY_A)) {
            Move(MyVector3 {0.01f, 0.0f, 0.0f});
        } else if (IsKeyDown(KEY_D)) {
            Move(MyVector3 {-0.01f, 0.0f, 0.0f});
        } else if (IsKeyDown(KEY_W)) {
            Move(MyVector3 {0.0f, 0.0f, 0.01f});
        } else if (IsKeyDown(KEY_S)) {
            Move(MyVector3 {0.0f, 0.0f, -0.01f});
        } else if (IsKeyDown(KEY_Q)) {
            Move(MyVector3 {0.0f, 0.01f, 0.0f});
        } else if (IsKeyDown(KEY_E)) {
            Move(MyVector3 {0.0f, -0.01f, 0.0f});
        }
        if (IsKeyPressed(KEY_P)) {
            std::cout << position.x << "x " << position.y << "y "<< position.z << "z" << std::endl;
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
