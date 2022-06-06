/*
** EPITECH PROJECT, 2022
** GameSound.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_GAMESOUND_HPP
#define BOMBERMAN_GAMESOUND_HPP

#pragma once
#include "IEntity.hpp"

namespace bomberman {
    class GameSound : public IEntity {
    private:
        Sound sound{};
        bool active;
        bool startActive;
    public:
        explicit GameSound(const std::string &soundPath);

        ~GameSound() override;

        void Update() {
        }

        void Reset();

        void SetActive(bool activate);

        void Move(Vector3 velocity) {
            (void) velocity;
        }

        void Play();

        void Stop();
    };
}
#endif //BOMBERMAN_GAMESOUND_HPP
