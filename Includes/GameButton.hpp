/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** GameButton
*/

#pragma once
#include "IEntity.hpp"
#include "Objects.hpp"

namespace bomberman {
    class GameButton : public IEntity {
        private:
            Texture2D _button;
            MyRectangle _bounds;
            int _btnState = 0;
        public:
            GameButton(std::string texturePath, int x, int y, int width, int height);
            ~GameButton();
        protected:
    };
}