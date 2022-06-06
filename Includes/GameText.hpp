/*
** EPITECH PROJECT, 2022
** GameText.hpp
** File description:
** GameText
*/

#ifndef GAMETEXT_HPP_
#define GAMETEXT_HPP_

#pragma once
#include "IEntity.hpp"
#include "Color.hpp"
#include "Objects.hpp"

namespace bomberman {
    class GameText : public IEntity {
        private:
            Font _font{};
            std::string _msg;
            MyVector2 _fontPosition;
            float _fontSize;
            bool _flash;
            MyColor _color;
            bool active{};
            int _framesCounter;

        public:
            GameText(const std::string &font, const std::string &msg, float x, float y, float fontSize, MyColor color, bool flash = false);
            ~GameText() override = default;
            void Draw();

            void Reset();
            void Update();
            void SetActive(bool activate);
            void Move(MyVector3 velocity);
    };
}

#endif /* !GAMETEXT_HPP_ */
