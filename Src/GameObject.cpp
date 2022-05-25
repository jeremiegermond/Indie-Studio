/*
** EPITECH PROJECT, 2022
** GameObject.cpp
** File description:
** TODO
*/

#include "GameObject.hpp"

namespace bomberman {
    void GameObject::draw() {
        DrawModel(model, (Vector3){0, 1, 0}, 1, WHITE);
    }

    void GameObject::UpdateAnimation() {
        if (!anim_path.empty()) {
            UpdateModelAnimation(model, animation[0], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= animation[0].frameCount)
                animFrameCounter = 0;
        }
    }

    GameObject::GameObject(std::string modelPath, std::string texturePath, std::string animPath) {
        count = 1;
        animFrameCounter = 0;
        model_path = std::move(modelPath);
        texture_path = std::move(texturePath);
        anim_path = animPath;
    }

    GameObject::GameObject(std::string modelPath) {
        count = 1;
        animFrameCounter = 0;
        model_path = modelPath;
    }

    GameObject::~GameObject() {
        if (!anim_path.empty()) {
            for (unsigned int i = 0; i < count; i++)
                UnloadModelAnimation(animation[i]);
            RL_FREE(animation);
        }
        if (!texture_path.empty())
            UnloadTexture(texture);
        UnloadModel(model);
    }

    void GameObject::load() {
        model = LoadModel(model_path.c_str());
        if (!texture_path.empty()) {
            texture = LoadTexture(texture_path.c_str());
            SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
        }
        if (!anim_path.empty())
            animation = LoadModelAnimations(anim_path.c_str(), &count);
    }
}