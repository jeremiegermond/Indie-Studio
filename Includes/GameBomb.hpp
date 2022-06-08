/*
** EPITECH PROJECT, 2022
** GameBomb.hpp
** File description:
** TODO
*/
#ifndef BOMBERMAN_GAMEBOMB_HPP
#define BOMBERMAN_GAMEBOMB_HPP

#include "GameObject.hpp"

namespace bomberman {
    class GameBomb : public AnimatedGameObject {
    public:
        GameBomb(const std::string &modelPath,
                   const std::string &texturePath,
                   const std::string &animationPath,
                   unsigned int animationCount,
                   float scale = 1.0f);
        void Update() override;
    };
}
#endif //BOMBERMAN_GAMEBOMB_HPP
