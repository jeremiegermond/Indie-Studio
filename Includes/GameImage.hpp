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
            Image _image;
            Texture2D _texture;
            MyColor _color;
            MyVector2 _position;
            bool active{};

        public:
            GameImage(const std::string &image, float x, float y, MyColor color);
            ~GameImage() override = default;
            void Draw();

            void Update() {}
            void Reset() {}
            void SetActive(bool activate);
            void Move(MyVector3 velocity) {
                (void) velocity;
            }
    };
}

#endif /* !GAMEIMAGE_HPP_ */
