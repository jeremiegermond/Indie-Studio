/*
** EPITECH PROJECT, 2022
** GameScript.hpp
** File description:
** GameScript
*/

#ifndef GAMESCRIPT_HPP_
#define GAMESCRIPT_HPP_

#include "IEntity.hpp"
#include "Objects.hpp"

namespace bomberman {
    class Game;
    class GameScript : public IEntity {
        private:
            bool active{};
            int currentScript;
            Game *_game;
            std::vector<MyVector3> positions;
            std::vector<MyVector3> rotations;

        public:
            GameScript(Game *game, int script);
            ~GameScript() override = default;
            void PressToZoom();
            void PressToPlay();

            void Reset();
            void Update();
            void SetActive(bool activate);
    };
}

#endif /* !GAMESCRIPT_HPP_ */
