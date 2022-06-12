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
            void Update();
            void SetActive(bool activate);
            void SetText(std::string new_msg) {
                _msg = new_msg;
            }
    };

    class GameLoading : public GameText {
        private:
            int _percentage;
        public:
            GameLoading() : GameText("../Assets/Font/Beauty_Forest.free.ttf", "Loading...\n\t0%", 855, 400, 125, WHITE) {
                _percentage = 0;
            };
            void UpdateAndDraw(int new_percentage) {
                _percentage = new_percentage;
                BeginDrawing();
                ClearBackground(BLACK);
                SetText("Loading...\n\t" + std::to_string(_percentage) + "%");
                Draw();
                EndDrawing();
            }
    };
}

#endif /* !GAMETEXT_HPP_ */
