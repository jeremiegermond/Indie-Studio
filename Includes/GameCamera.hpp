/*
** EPITECH PROJECT, 2022
** GameCamera.hpp
** File description:
** TODO
*/

#pragma once
#include "IEntity.hpp"
#include "Objects.hpp"

namespace bomberman {
    class GameCamera : public IEntity {
    private:
        MyCamera camera{};
        MyVector3 startPosition;
        MyCamera objectiveCam{};
        MyVector3 startTarget;
        MyVector3 startUp;
        float startFov;
        int startProjection;
        bool active;
    public:
        GameCamera() : GameCamera(MyVector3{-10.0f, 15.0f, -10.0f},
                             MyVector3{0.0f, 0.0f, 0.0f},
                             MyVector3{0.0f, 1.0f, 0.0f},
                             20.0f,
                             CAMERA_PERSPECTIVE) {
        };

        GameCamera(MyVector3 position, MyVector3 target, MyVector3 up, float fov, int projection);
        ~GameCamera() override = default;

        void Reset();
        void Update();
        void SetActive(bool activate);
        void Move(Vector3 velocity);
        void SetObjectiveCam(MyCamera objective);
        bool IsOnObjective();
        void MoveToObjective();

        MyCamera GetCamera() {
            return camera;
        }

        MyVector3 GetStartPosition() {
            return startPosition;
        }

        void SetMode(int mode);
    };
}
