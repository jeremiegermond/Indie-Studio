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

        void Update() override {}
        void Reset() override;
        void SetActive(bool activate) override;
        void Move(MyVector3 velocity) override {
            (void) velocity;
        }
        void Play();
        void Stop();
    };
}
