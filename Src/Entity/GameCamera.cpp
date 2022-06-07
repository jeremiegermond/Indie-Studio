/*
** EPITECH PROJECT, 2022
** GameCamera.cpp
** File description:
** TODO
*/

#include "GameCamera.hpp"

namespace bomberman {
    GameCamera::GameCamera(MyVector3 position,
                           MyVector3 target,
                           MyVector3 up,
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
        objectiveCam = camera;
    }

    void GameCamera::Reset() {
        camera.position = startPosition;
        camera.target = startTarget;
        camera.up = startUp;
        camera.fovy = startFov;
        camera.projection = startProjection;
        objectiveCam = camera;
    }

    void GameCamera::Update() {
        if (active) {
            if (!IsOnObjective()) {
                MoveToObjective();
            }
            if (IsKeyDown(KEY_J))
                objectiveCam.position.x += .01;
            if (IsKeyDown(KEY_K))
                objectiveCam.position.x -= .01;
            if (IsKeyDown(KEY_N))
                objectiveCam.position.z += .01;
            if (IsKeyDown(KEY_M))
                objectiveCam.position.z -= .01;
            if (IsKeyDown(KEY_I))
                objectiveCam.position.y += .01;
            if (IsKeyDown(KEY_O))
                objectiveCam.position.y -= .01;
            if (IsKeyDown(KEY_R))
                objectiveCam.position = startPosition;
            if (IsKeyDown(KEY_C))
                objectiveCam.fovy -= 1;
            if (IsKeyDown(KEY_V))
                objectiveCam.fovy += 1;
            if (IsKeyPressed(KEY_P)) {
                printf("targ: %f %f %f\n", camera.position.x, camera.position.y, camera.position.z);
                printf("fov: %f\n", camera.fovy);
            }
            UpdateCamera(&camera);
        }
    }

    void GameCamera::SetActive(bool activate) {
        active = activate;
    }

    void GameCamera::Move(Vector3 velocity) {
        camera.position.x = velocity.x;
        camera.position.y = velocity.y;
        camera.position.z = velocity.z;
    }

    void GameCamera::SetMode(int mode) {
        SetCameraMode(camera, mode);
    }

    void GameCamera::SetObjectiveCam(MyCamera objective) {
        objectiveCam = objective;
    }

    bool GameCamera::IsOnObjective() {
        Vector3 v1 = camera.position;
        Vector3 v2 = objectiveCam.position;
        if (Vector3Distance(v1, v2) > 0.1f)
            return false;
        if (abs(camera.fovy - objectiveCam.fovy) > 0.5f)
            return false;
        return true;
    }

    void GameCamera::MoveToObjective() {
        Vector3 v1 = camera.position;
        Vector3 v2 = objectiveCam.position;
        Vector3 v3 = Vector3Lerp(v1, v2, 0.5f);
        Move(v3);
        camera.fovy = Lerp(camera.fovy, objectiveCam.fovy, 1.0f);
    }
}