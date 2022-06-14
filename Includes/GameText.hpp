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
#include "GamePlayer.hpp"

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
            virtual void Draw();
            virtual void Update();
            void SetActive(bool activate);
            bool IsActive() { return active; }
            void SetText(std::string new_msg) {
                _msg = new_msg;
            }
            void SetPosition(MyVector2 new_pos) {
                _fontPosition.x = new_pos.x;
                _fontPosition.y = new_pos.y;
            }
            MyVector2 GetPosition() {
                return _fontPosition;
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

    class GamePowerUp : public GameText {
        private:
            GamePlayer *pPlayer{};
            int _maxBombsStat;
            float _speed;
            int _fireUp;
            float _wall;

        public:
            GamePowerUp() : GameText("../Assets/Font/Beauty_Forest.free.ttf", "", 0, 0, 80, BLACK) {
            }

            void SetPlayer(GamePlayer *player) {
                pPlayer = player;
            }

            void Update() override {
                GameText::Update();
                if (!IsActive() || pPlayer == nullptr)
                    return;
                _maxBombsStat = pPlayer->GetMaxBombs();
                _speed = pPlayer->GetSpeed();
                _fireUp = pPlayer->GetFireUps();
                _wall = pPlayer->GetWall();
                SetText(TextFormat("%d\t%.f", _maxBombsStat, _speed));
            }
            void Draw() override {
                GameText::Draw();
                SetText(TextFormat("%d %.f", _fireUp, _wall));
                MyVector2 currentPos = GetPosition();
                currentPos.y += 90;
                SetPosition(currentPos);
                GameText::Draw();
                currentPos.y -= 90;
                SetPosition(currentPos);
            }
    };
}

#endif /* !GAMETEXT_HPP_ */
