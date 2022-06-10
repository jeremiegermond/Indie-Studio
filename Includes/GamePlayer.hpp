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
    class Game;

    class GamePlayer : public AnimatedGameObject {
    private:
        Game *pGame;
    public:
        GamePlayer(const std::string &modelPath,
                   const std::string &texturePath,
                   const std::string &animationPath,
                   Game *game,
                   unsigned int animationCount = 0,
                   float scale = 1.0f);

        GamePlayer(const std::string &modelPath,
                   const std::string &texturePath,
                   Game *game,
                   unsigned int animationCount = 0,
                   float scale = 1.0f)
                : GamePlayer(modelPath, texturePath, modelPath, game, animationCount, scale) {
        }

        void Update() override;
    };
}

#endif //BOMBERMAN_GAMEPLAYER_HPP
