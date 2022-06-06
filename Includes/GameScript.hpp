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
            bool active;
            int _nbScript;
            Game *_game;
        
        public:
            GameScript(Game *game, int nbScript);
            ~GameScript() override;
            void PressEnterToPlay();
            void FinishSelectGoToPlay();

            void Reset();
            void Update();
            void SetActive(bool activate);
            void Move(Vector3 velocity);
    };
}

#endif /* !GAMESCRIPT_HPP_ */
