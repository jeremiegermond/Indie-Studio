/*
** EPITECH PROJECT, 2022
** GameImage.hpp
** File description:
** GameImage
*/

#ifndef GAMEIMAGE_HPP_
#define GAMEIMAGE_HPP_

#include "IEntity.hpp"
#include "Color.hpp"

namespace bomberman {
    class GameImage : public IEntity {
        private:
            Image _image{};
            Texture2D _texture{};
            MyColor _color;
            int posX;
            int posY;
            bool active{};

        public:
            GameImage(const std::string &image, int x, int y, MyColor color = WHITE);
            ~GameImage() override = default;
            void Draw();
            void SetActive(bool activate);
            void SetColor(MyColor color);
    };
}

#endif /* !GAMEIMAGE_HPP_ */
