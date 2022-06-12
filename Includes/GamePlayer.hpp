/*
** EPITECH PROJECT, 2022
** GamePlayer.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_GAMEPLAYER_HPP
#define BOMBERMAN_GAMEPLAYER_HPP

#include "GameObject.hpp"
#include "GameBomb.hpp"
#include "GameDrawMap.hpp"

namespace bomberman {

    class GamePlayer : public AnimatedGameObject {
    private:
        bool canPlay{};
        std::vector<GameBomb *> bombs;
        GameDrawMap *map{};
        int fireUp;
        int lives;
        int maxBombsStat;
        tPoint now;
        tPoint previous;
        double elapsed{};
        bool cpu = true;
        Keyboard *keys = nullptr;
    public:
        GamePlayer(const std::string &modelPath,
                   const std::string &texturePath,
                   const std::string &animationPath,
                   float scale = 1.0f,
                   unsigned int animationCount = 1)
                : AnimatedGameObject(modelPath, texturePath, animationPath, animationCount, scale),
                  fireUp(3), lives(1), maxBombsStat(1), previous(std::chrono::system_clock::now()) {
        }

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

        std::vector<GameBomb *> GetBombs();

        void RemoveLive();

        void SetMap(GameDrawMap *newMap);

        bool is_cpu();

        void switchPlayer();

        void setCpu(bool nv);
    };
}

#endif //BOMBERMAN_GAMEPLAYER_HPP
