/*
** EPITECH PROJECT, 2022
** GameSound.hpp
** File description:
** TODO
*/

#pragma once

#include "IEntity.hpp"
#include "Objects.hpp"
#include "Sound.hpp"

namespace bomberman {
    class GameSound : public IEntity {
    private:
        Sound sound{};
        bool active;
        bool startActive;
        bool looping;
    public:
        explicit GameSound(const std::string &soundPath, bool looping = false);
        ~GameSound() override;

        void Update();
        void Reset();
        void SetActive(bool activate);
        void Play();
        void Stop();
    };
}
