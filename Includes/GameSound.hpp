/*
** EPITECH PROJECT, 2022
** GameSound.hpp
** File description:
** TODO
*/

#pragma once

#include "IEntity.hpp"
#include "Objects.hpp"

namespace bomberman {
    class GameSound : public IEntity {
    private:
        Sound sound{};
        bool active;
        bool startActive;

    public:
        explicit GameSound(const std::string &soundPath);
        ~GameSound() override;

        void Update() {}
        void Reset();
        void SetActive(bool activate);
        void Move(MyVector3 velocity) {
            (void) velocity;
        }
        void Play();
        void Stop();
    };
}
