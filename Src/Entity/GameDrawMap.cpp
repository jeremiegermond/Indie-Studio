/*
** EPITECH PROJECT, 2022
** GameDrawMap.cpp
** File description:
** GameDrawMap
*/

#include "GameDrawMap.hpp"

namespace bomberman {

    GameDrawMap::GameDrawMap(const std::string &texturePathBrick, const std::string &texturePathWood, MyColor color) {
        _cubePosition.x = 0;
        _cubePosition.y = 0;
        _cubePosition.z = 0;
        _imageBrick = LoadImage(texturePathBrick.c_str());
        _imageWood = LoadImage(texturePathWood.c_str());
        _textureBrick = LoadTextureFromImage(_imageBrick);
        _textureWood = LoadTextureFromImage(_imageWood);
        _color = color;
        GenerateMap();
        Save();
    }

    GameDrawMap::~GameDrawMap() {
        _map.erase(_map.begin());
    }
            
    void GameDrawMap::Draw() {
        _cubePosition.z = -10;
        for (auto y: _map) {
            _cubePosition.x = -10;
            for (auto x: y) {  
                if (x == '1') {
                    DrawCubeTexture(_textureBrick, _cubePosition, 1.0f, 1.0f, 1.0f, _color);
                }
                else if (x == '2') {
                    DrawCubeTexture(_textureWood, _cubePosition, 1.0f, 1.0f, 1.0f, _color);
                }
                else if (x == '4') {    // DEBUG
                    DrawCube(_cubePosition, 1.0f, 1.0f, 1.0f, RED);
                }
                else if (x == '5') {    // DEBUG
                    DrawCube(_cubePosition, 1.0f, 1.0f, 1.0f, BLUE);
                }
                else if (x == '6') {    // DEBUG
                    DrawCube(_cubePosition, 1.0f, 1.0f, 1.0f, YELLOW);
                }
                else if (x == '7') {    // DEBUG
                    DrawCube(_cubePosition, 1.0f, 1.0f, 1.0f, PURPLE);
                }
                else if (x == '8') {    // DEBUG
                    DrawCube(_cubePosition, 1.0f, 1.0f, 1.0f, ORANGE);
                }
                else if (x != '0') {    //
                    DrawCube(_cubePosition, 1.0f, 1.0f, 1.0f, GREEN);
                }
                _cubePosition.x++;
            }
            _cubePosition.z++;
        }
    }

    void GameDrawMap::GenerateMap() {
        char type = '0';
        int enemyTotal = 4;
        int width = 21;
        int height = 21;

        srand(time(NULL));
        _map.resize(height);
        std::cout << "creating map" << std::endl;
        for (int row = 0; row < height; row++) {
            _map[row].resize(width);
            for (int col = 1; col <= width; col++) {
                if ((row == 2 || row == height - 3) && (col == 3 || col == width - 2))
                    type = '0';
                else if ((row == 2 || row == height - 3) && (col == 4 || col == width - 3))
                    type = '0';
                else if ((row == 3 || row == height - 4) && (col == 3 || col == width - 2))
                    type = '0';
                else if ((row + 1) % 2 == 0 && col % 2 == 0)
                    type = '1';
                else if ((col >= 2 && col <= width -1) && (row == 1 || row == height - 2))
                    type = '1';
                else if ((row >= 1 && row <= height - 2) && (col == 2 || col == width - 1))
                    type = '1';
                else if (row > 1 && row < height - 1 && col > 2 && col < width)
                    type = Populate(enemyTotal);
                else
                    type = '0';
                std::cout << type << " ";
                _map[row][col - 1] = type;
            }
            type = '0';
            std::cout << " | " << row + 1 << std::endl;
        }
    } 

    char GameDrawMap::Populate(int enemyTotal) {
        int random = static_cast<int>(rand() % 100);

        if (random % 5 == 0) {
            if (random <= 25)
                return '5';
            else if (random <= 50)
                return '6';
            else if (random <= 75)
                return '7';
            else
                return '8';
        }
        return random % 2 == 0 ? '0' : '2';
    }

    char GameDrawMap::GetBlock(int posX,
                               int posY) {
        posX += 10;
        posY += 10;
        if (isIn(posX, posY))
            return _map[posY][posX];
        return '1';
    }

    void GameDrawMap::BreakBlock(int posX,
                                 int posY) {
        posX += 10;
        posY += 10;
        if (!isIn(posX, posY))
            return;
        printf("%c[%d][%d]\n", _map[posY][posX], posY, posX);
        if (_map[posY][posX] != '0' && _map[posY][posX] != '1') {
            _map[posY][posX] = '0';
        }
    }

    bool GameDrawMap::isIn(int posX, int posY) {
        if (posY < 0 || posX < 0 || posY >= int(_map.size()))
            return false;
        if (posX >= int(_map[posY].size()))
            return false;
        return true;
    }

    void GameDrawMap::Save() {
        std::ofstream file;

        file.open("map.txt");
        if (!file.is_open())
            return;
        for (auto y: _map) {
            for (auto x: y) {
                file << x;
            }
            file << '\n';
        }
        file.close();
    }
}

/*
0 : void
1 : stone block
2 : wood block
3 : player
4 : enemy
5 : bomb up 
6 : speed up 
7 : fire up 
8 : wall pass 
*/