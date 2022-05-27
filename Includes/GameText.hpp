/*
** EPITECH PROJECT, 2022
** GameText.hpp
** File description:
** GameText
*/

#ifndef GAMETEXT_HPP_
#define GAMETEXT_HPP_

#include "IEntity.hpp"

namespace bomberman {
    class GameText : public IEntity {
        private:
            Font font;

        public:
            GameText(Font font);
            ~GameText();
            void LinkFontText();
    };
}

#endif /* !GAMETEXT_HPP_ */
