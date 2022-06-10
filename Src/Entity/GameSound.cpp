/*
** EPITECH PROJECT, 2022
** GameSound.cpp
** File description:
** TODO
*/

#include "GameSound.hpp"

namespace bomberman {

    GameSound::GameSound(const std::string &soundPath, bool looping)
            : active(true), startActive(true), looping(looping) {
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
        if (IsSoundPlaying(sound))
            StopSound(sound);
    }

    void GameSound::Update() {
        if (active)
            if (!IsSoundPlaying(sound))
                PlaySound(sound);
    }
}