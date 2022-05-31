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
            Font _font;
            std::string _msg;
            Vector2 _fontPosition;
            float _fontSize;
            bool _flash;
            Color _color;
            bool active;

        public:
            GameText(const std::string &font, const std::string &msg, float x, float y, float fontSize, Color color, bool flash = false);
            ~GameText() override;
            void Draw();

            void Reset() override;
            void Update() override;
            void SetActive(bool activate) override;
            void Move(Vector3 velocity) override;
    };
}

#endif /* !GAMETEXT_HPP_ */
