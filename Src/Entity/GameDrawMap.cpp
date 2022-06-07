/*
** EPITECH PROJECT, 2022
** GameDrawMap.cpp
** File description:
** GameDrawMap
*/

#include "GameDrawMap.hpp"

namespace bomberman {

    GameDrawMap::GameDrawMap(MyColor color) {
         _cubePosition.x = 0;
        _cubePosition.y = 0;
        _cubePosition.z = 0;
        _color = color;
        GenerateMap();
    }

    GameDrawMap::~GameDrawMap() {
        _map.erase(_map.begin());
    }
            
    void GameDrawMap::Draw() {
        _cubePosition.y = 0;
        for (auto y: _map) {
            _cubePosition.x = 0;
            for (auto x: y) {  
                if (x == '1') {
                    DrawCube(_cubePosition, 1.0f, 1.0f, 1.0f, _color);
                }
                _cubePosition.x++;
            }
            _cubePosition.y++;
        }
    }

    void GameDrawMap::SetActive(bool activate) {
        active = activate;
    }

    void GameDrawMap::GenerateMap() {
        char type = '0';
        int enemyTotal = 4;
        int width = 20;
        int height = 20;

        srand(time(NULL));
        _map.resize(height);
        std::cout << "creating map" << std::endl;
        for (int row = 0; row < height; row++) {
            _map[row].resize(width);
            for (int col = 1; col <= width; col++)
            {
                if (col == 3 && row == 2)
                    type = '3';
                else if ((col == 4 && row == 2) || (col == 3 && row == 3))
                    type = '0';
                else if ((col == 5 && row == 2) || (col == 3 && row == 4))
                    type = '0';
                else if (col == 1 || col == width || row == 0 || row == height - 1)
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

        if (random >= 80) {
            if (rand() % 100 < 5) {
                return ('7');
            }
            else if (rand() % 100 < 7) {
                return ('6');
            }
            return ('2');
        }
        if (random > 20 && random <= 25 && enemyTotal > 0) {
            enemyTotal -= 1;
            return (rand() % 10 <= 5 ? '4' : '5');
        }
        return ('0');
    }
}   
