/*
** EPITECH PROJECT, 2022
** GameDrawMap.hpp
** File description:
** GameDrawMap
*/

#ifndef GAMEDRAWMAP_HPP_
#define GAMEDRAWMAP_HPP_

#include "IEntity.hpp"

namespace bomberman {
    class GameDrawMap : public IEntity {
        private:
            bool active{};
            MyVector3 _cubePosition;
            MyColor _color;
            Texture2D _textureBrick{};
            Texture2D _textureWood{};
            std::vector<std::vector<char>> _map;
            Image _imageBrick{};
            Image _imageWood{};
        
        public:
            GameDrawMap(const std::string &texturePathBrick, const std::string &texturePathWood, MyColor color);
            ~GameDrawMap() override;
            void Draw();
            void GenerateMap();
            char Populate(int enemyTotal);
            bool isIn(int posX, int posY);
            char GetBlock(int posX, int posY);
            void BreakBlock(int posX, int posY);
            void Save();
    };
}


#endif /* !GAMEDRAWMAP_HPP_ */
