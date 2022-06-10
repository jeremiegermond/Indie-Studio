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
    typedef std::chrono::system_clock::time_point tPoint;

    class GameBomb : public AnimatedGameObject {
    private:
        tPoint explode;
        tPoint end_life;
        bool exploded{};
        AnimatedGameObject *explosion{};
        Sound boom;
    public:
        GameBomb(const std::string &modelPath,
                 const std::string &texturePath,
                 const std::string &animationPath,
                 unsigned int animationCount = 0,
                 float scale = 1.0f);

        GameBomb(const std::string &modelPath,
                 const std::string &texturePath,
                 unsigned int animationCount = 0,
                 float scale = 1.0f)
                : GameBomb(modelPath, texturePath, modelPath, animationCount, scale) {
        }

        void Update() override;

        bool GetExplode() const;

        void Draw() override;
    };
}
#endif //BOMBERMAN_GAMEBOMB_HPP
