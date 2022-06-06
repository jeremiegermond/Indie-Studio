/*
** EPITECH PROJECT, 2022
** GameCamera.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_GAMECAMERA_HPP
#define BOMBERMAN_GAMECAMERA_HPP

#pragma once
#include "IEntity.hpp"

namespace bomberman {
    class GameCamera : public IEntity {
    private:
        Camera3D camera{};
        Vector3 startPosition;
        Vector3 startTarget;
        Vector3 startUp;
        float startFov;
        int startProjection;
        bool active;
    public:
        GameCamera()
                : GameCamera(Vector3{-10.0f, 15.0f, -10.0f},
                             Vector3{0.0f, 0.0f, 0.0f},
                             Vector3{0.0f, 1.0f, 0.0f},
                             20.0f,
                             CAMERA_PERSPECTIVE) {
        };

        GameCamera(Vector3 position,
                   Vector3 target,
                   Vector3 up,
                   float fov,
                   int projection);

        ~GameCamera() override = default;

        void Reset();

        void Update();

        void SetActive(bool activate);

        void Move(Vector3 velocity);

        Camera3D GetCamera() {
            return camera;
        }

        void SetMode(int mode);
    };
}

#endif //BOMBERMAN_GAMECAMERA_HPP
