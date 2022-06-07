/*
** EPITECH PROJECT, 2022
** GameDrawMap.hpp
** File description:
** GameDrawMap
*/

#ifndef GAMEDRAWMAP_HPP_
#define GAMEDRAWMAP_HPP_

#include "IEntity.hpp"
#include "Color.hpp"

namespace bomberman {
    class GameDrawMap : public IEntity {
        private:
            bool active{};
            MyVector3 _cubePosition;
            MyColor _color;
        
        public:
            GameDrawMap(MyVector3 cubePosition, MyColor color);
            ~GameDrawMap() override = default;
            void Draw();

            void Update() {}
            void Reset() {}
            void SetActive(bool activate);
            void Move(MyVector3 velocity) {
                (void) velocity;
            }
    };
}


#endif /* !GAMEDRAWMAP_HPP_ */
