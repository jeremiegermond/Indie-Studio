/*
** EPITECH PROJECT, 2022
** GameScript.hpp
** File description:
** GameScript
*/

#ifndef GAMESCRIPT_HPP_
#define GAMESCRIPT_HPP_

#include "IEntity.hpp"

namespace bomberman {
    class Game;
    class GameScript : public IEntity {
        private:
            bool active{};
            int currentScript;
            Game *_game;
            std::vector<MyVector3> positions;
            std::vector<MyVector3> rotations;
            std::vector<MyVector2> powerUpPos;
            std::vector<KeyboardKey*> keys;
            Sound click{};

        public:
            GameScript(Game *game, int script);
            ~GameScript() override = default;
            void PressToZoom();
            void PressToPlay();
            void SelectLoad();

            void Reset();
            void Update();
            void SetActive(bool activate);
            void UpdateBomb();
            void LoadPlayers(bool populated = false);
            void ActivateSelection();
    };
}

#endif /* !GAMESCRIPT_HPP_ */
