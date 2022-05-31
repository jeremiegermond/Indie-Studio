/*
** EPITECH PROJECT, 2022
** GamePlayer.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_GAMEPLAYER_HPP
#define BOMBERMAN_GAMEPLAYER_HPP

#include "GameObject.hpp"

namespace bomberman {
    class GamePlayer : public AnimatedGameObject {
    public:
        GamePlayer(const std::string &modelPath,
                   const std::string &texturePath,
                   const std::string &animationPath,
                   unsigned int animationCount);
        void Update() override;
    };
}

#endif //BOMBERMAN_GAMEPLAYER_HPP
