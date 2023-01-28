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
        tPoint now;
        tPoint previous;
        double elapsed{};
        int exploded{};
        int fireUp;
        AnimatedGameObject *explosion{};
        Sound boom{};
        std::vector<MyVector3> explosionPos;

    public:
        GameBomb(int fireUp);

        void Update() override;

        int GetExplode();

        int GetFire() const;

        void Draw() override;

        void AddExplosion(MyVector3 pos);
    };
}
#endif //BOMBERMAN_GAMEBOMB_HPP
