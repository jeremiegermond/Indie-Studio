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
            int _nbScript;
            Game *_game;
        
        public:
            GameScript(Game *game, int nbScript);
            ~GameScript() override = default;
            void PressEnterToPlay();
            void FinishSelectGoToPlay();

            void Reset() override;
            void Update() override;
            void SetActive(bool activate) override;
            void Move(MyVector3 velocity) override;
    };
}

#endif /* !GAMESCRIPT_HPP_ */
