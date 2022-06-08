/*
** EPITECH PROJECT, 2022
** GameImage.hpp
** File description:
** GameImage
*/

#ifndef GAMEIMAGE_HPP_
#define GAMEIMAGE_HPP_

#include "IEntity.hpp"

namespace bomberman {
    class GameImage {
        private:
            Image _image;
            bool active{};

        public:
            GameImage();
            ~GameImage();
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
