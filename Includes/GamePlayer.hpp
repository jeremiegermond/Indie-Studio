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
    class GameBomb;

    class GamePlayer : public AnimatedGameObject {
    private:
        bool canPlay{};
        std::vector<GameBomb *> bombs;
        Keyboard *keys{};
    public:
        GamePlayer(const std::string &modelPath,
                   const std::string &texturePath,
                   const std::string &animationPath,
                   float scale = 1.0f,
                   unsigned int animationCount = 1) : AnimatedGameObject(modelPath, texturePath, animationPath, animationCount, scale) {}

        GamePlayer(const std::string &modelPath,
                   const std::string &texturePath,
                   float scale = 1.0f,
                   unsigned int animationCount = 1)
                : GamePlayer(modelPath, texturePath, modelPath, scale, animationCount) {
        }

        void Update() override;

        void SetPlay(bool play);
    
        void SetKeys(KeysLayout playerNB);
    
        void SetKeys(int playerNB);

        std::vector<GameBomb *>GetBombs();

    };
}

#endif //BOMBERMAN_GAMEPLAYER_HPP
