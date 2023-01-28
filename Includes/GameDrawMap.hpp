/*
** EPITECH PROJECT, 2022
** GameDrawMap.hpp
** File description:
** GameDrawMap
*/

#ifndef GAMEDRAWMAP_HPP_
#define GAMEDRAWMAP_HPP_

#include "IEntity.hpp"
#include "GameCamera.hpp"

#define MAP_HEIGHT 17
#define MAP_WIDTH 21
//#define Y_OFFSET 8
#define Y_OFFSET (MAP_HEIGHT/2)
#define X_OFFSET (MAP_WIDTH/2)
namespace bomberman {
    class GameDrawMap : public IEntity {
        private:
            MyVector3 _cubePosition;
            MyColor _color;
            Texture2D _textureBrick{};
            Texture2D _textureWood{};
            Texture2D _textureFire{};
            Texture2D _textureBomb{};
            Texture2D _textureSpeed{};
            Texture2D _textureWall{};
            Model planeModel;
            Texture2D _planeTexture;
            std::vector<std::vector<char>> _map;
            int breakTiles;
        public:
            GameDrawMap(const std::string &texturePathBrick, const std::string &texturePathWood, MyColor color);
            ~GameDrawMap() override;
            void Draw(GameCamera *camera);
            void GenerateMap();
            static char Populate(bool Break = false);
            bool isIn(int posX, int posY);
            char GetBlock(int posX, int posY);
            void BreakBlock(int posX, int posY, bool GetPowerUp = false, double wallPass = 0);
            void Save();
            void LoadMap();
            bool Collide(int posX, int posY, double wallPass = 0);
            bool GetBreakTiles();
    };
}


#endif /* !GAMEDRAWMAP_HPP_ */
