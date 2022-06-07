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
#include "vector"

namespace bomberman {
    class GameDrawMap : public IEntity {
        private:
            bool active{};
            MyVector3 _cubePosition;
            MyColor _color;
            std::vector<std::vector<char>> _map;
        
        public:
            GameDrawMap(MyColor color);
            ~GameDrawMap() override;
            void Draw();
            void GenerateMap();
            char Populate(int enemyTotal);

            void Update() {}
            void Reset() {}
            void SetActive(bool activate);
            void Move(MyVector3 velocity) {
                (void) velocity;
            }
    };
}


#endif /* !GAMEDRAWMAP_HPP_ */
