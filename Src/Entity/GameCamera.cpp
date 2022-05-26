/*
** EPITECH PROJECT, 2022
** GameCamera.cpp
** File description:
** TODO
*/

#include "GameCamera.hpp"

namespace bomberman {
    GameCamera::GameCamera(Vector3 position,
                           Vector3 target,
                           Vector3 up,
                           float fov,
                           int projection)
            : startPosition(position),
              startTarget(target),
              startUp(up),
              startFov(fov),
              startProjection(projection),
              active(true) {
        camera.position = position;
        camera.target = target;
        camera.up = up;
        camera.fovy = fov;
        camera.projection = projection;
    }

    void GameCamera::Reset() {
        camera.position = startPosition;
        camera.target = startTarget;
        camera.up = startUp;
        camera.fovy = startFov;
        camera.projection = startProjection;
    }

    void GameCamera::Update() {
        if (active)
            UpdateCamera(&camera);
    }

    void GameCamera::SetActive(bool activate) {
        active = activate;
    }

    void GameCamera::Move(Vector3 velocity) {
        camera.position.x += velocity.x;
        camera.position.y += velocity.y;
        camera.position.z += velocity.z;
    }

    void GameCamera::SetMode(int mode) {
        SetCameraMode(camera, mode);
    }
}