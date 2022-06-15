/*
** EPITECH PROJECT, 2022
** GameSound.cpp
** File description:
** TODO
*/

#include "GameSound.hpp"

namespace bomberman {

    GameSound::GameSound(const std::string &soundPath, bool looping)
            : active(true), startActive(true) {
        if (!std::ifstream(soundPath).good())
            throw BuildError("Failed to load sound " + soundPath, __FILE__, __LINE__);
        sound = MySound::loadSound(soundPath.c_str());
        SetSoundVolume(sound, .2f);
    }

    GameSound::~GameSound() {
        Stop();
        MySound::unloadSound(sound);
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
            MySound::playSound(sound);
        } else
            Stop();
    }

    void GameSound::Stop() {
        if (IsSoundPlaying(sound))
            MySound::stopSound(sound);
    }

    void GameSound::Update() {
        if (active)
            if (!MySound::isSoundPlaying(sound))
                MySound::playSound(sound);
    }
}