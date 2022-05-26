/*
** EPITECH PROJECT, 2022
** GameSound.cpp
** File description:
** TODO
*/

#include "GameSound.hpp"

namespace bomberman {

    GameSound::GameSound(const std::string &soundPath)
            : active(true), startActive(true) {
        sound = LoadSound(soundPath.c_str());
    }

    GameSound::~GameSound() {
        Stop();
        UnloadSound(sound);
    }

    void GameSound::Reset() {
        Stop();
        SetActive(startActive);
    }

    void GameSound::SetActive(bool activate) {
        active = activate;
        Play();
    }

    void GameSound::Play() {
        if (active) {
            PlaySound(sound);
        } else
            Stop();
    }

    void GameSound::Stop() {
        StopSound(sound);
    }
}