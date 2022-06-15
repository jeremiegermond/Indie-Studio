/*
** EPITECH PROJECT, 2022
** GameDrawMap.cpp
** File description:
** GameDrawMap
*/

#include "GameDrawMap.hpp"

namespace bomberman {

    GameDrawMap::GameDrawMap(const std::string &texturePathBrick,
                             const std::string &texturePathWood,
                             MyColor color) {
        _cubePosition.x = 0;
        _cubePosition.y = 0;
        _cubePosition.z = 0;
        _textureBrick = Load::loadTexture(texturePathBrick.c_str());
        _textureWood = Load::loadTexture(texturePathWood.c_str());
        _textureFire = Load::loadTexture("../Assets/PowerUps/fireUp.png");
        _textureBomb = Load::loadTexture("../Assets/PowerUps/bomb.png");
        _textureSpeed = Load::loadTexture("../Assets/PowerUps/speed.png");
        _textureWall = Load::loadTexture("../Assets/PowerUps/wall.png");
        _color = color;
        _planeTexture = Load::loadTexture("../Assets/Level/plane.png");
        planeModel = Load::loadModelFromMesh(GenMeshPlane(19, 19, 19, 19));
        Load::setMaterialTexture(&planeModel.materials[0], MATERIAL_MAP_DIFFUSE, _planeTexture);
        _map.resize(21);
        for (int row = 0; row < 21; row++)
            _map[row].resize(21);
        GenerateMap();
    }

    GameDrawMap::~GameDrawMap() {
        _map.clear();
        Load::unloadTexture(_textureWood);
        Load::unloadTexture(_textureWood);
        Load::unloadTexture(_textureFire);
        Load::unloadTexture(_textureBomb);
        Load::unloadTexture(_textureSpeed);
        Load::unloadTexture(_textureWall);
        Load::unloadTexture(_planeTexture);
    }

    void GameDrawMap::Draw() {
        Draw::drawModel(planeModel, MyVector3{.0f,-.5f,.0f}, 1.f, LIGHTGRAY);
        _cubePosition.z = -10;
        for (auto y: _map) {
            _cubePosition.x = -10;
            for (auto x: y) {
                if (x == '1') {
                    Draw::drawCubeTexture(_textureBrick, _cubePosition, 1.0f, 1.0f, 1.0f, _color);
                } else if (x == '2') {
                    Draw::drawCubeTexture(_textureWood, _cubePosition, 1.0f, 1.0f, 1.0f, _color);
                } else if (x == '5') {
                    Draw::drawCubeTexture(_textureBomb, _cubePosition, 1.0f, 1.0f, 1.0f, _color);
                } else if (x == '6') {
                    Draw::drawCubeTexture(_textureSpeed, _cubePosition, 1.0f, 1.0f, 1.0f, _color);
                } else if (x == '7') {
                    Draw::drawCubeTexture(_textureWall, _cubePosition, 1.0f, 1.0f, 1.0f, _color);
                } else if (x == '8') {
                    Draw::drawCubeTexture(_textureFire, _cubePosition, 1.0f, 1.0f, 1.0f, _color);
                } else if (x != '0') {    //
                    Draw::drawCube(_cubePosition, 1.0f, 1.0f, 1.0f, GREEN);
                }
                _cubePosition.x++;
            }
            _cubePosition.z++;
        }
    }

    void GameDrawMap::GenerateMap() {
        char type = '0';
        int width = 21;
        int height = 21;

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
                else if ((col >= 2 && col <= width - 1) && (row == 1 || row == height - 2))
                    type = '1';
                else if ((row >= 1 && row <= height - 2) && (col == 2 || col == width - 1))
                    type = '1';
                else if (row > 1 && row < height - 1 && col > 2 && col < width)
                    type = Populate();
                else
                    type = '0';
                std::cout << type << " ";
                _map[row][col - 1] = type;
            }
            type = '0';
            std::cout << " | " << row + 1 << std::endl;
        }
    }

    char GameDrawMap::Populate(bool Break) {
        int random = static_cast<int>(std::rand() % 100);

        if (Break && random % 4 == 0) {
            if (random <= 25)
                return '5';
            else if (random <= 50)
                return '6';
            else if (random <= 75)
                return '7';
            else
                return '8';
        }
        return (Break || random % 6 == 0) ? '0' : '2';
    }

    char GameDrawMap::GetBlock(int posX,
                               int posY) {
        posX += 10;
        posY += 10;
        if (isIn(posX, posY))
            return _map[posY][posX];
        return '1';
    }

    bool GameDrawMap::Collide(int posX,
                              int posY,
                              double wallPass) {
        auto block = GetBlock(posX, posY);
        if (block == '1')
            return true;
        if (block == '2' && wallPass == 0)
            return true;
        return false;
    }

    void GameDrawMap::BreakBlock(int posX,
                                 int posY,
                                 bool GetPowerUp,
                                 double wallPass) {
        posX += 10;
        posY += 10;
        if (!isIn(posX, posY))
            return;
        if (_map[posY][posX] != '0' && _map[posY][posX] != '1') {
            if (wallPass) {
                if (_map[posY][posX] != '2')
                    _map[posY][posX] = '0';
                return;
            }
            _map[posY][posX] = GetPowerUp ? '0' : Populate(true);
        }
    }

    bool GameDrawMap::isIn(int posX,
                           int posY) {
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

    void GameDrawMap::LoadMap() {
        std::ifstream _loadmap;
        std::string oldmap;

        _loadmap.open("map.txt");
        if (!_loadmap.is_open()) {
            GenerateMap();
            return;
        }
        for (auto &y: _map) {
            std::getline(_loadmap, oldmap);
            if (oldmap.size() < 21)  {
                GenerateMap();
                return;
            }
            for (int x = 0; x < int(y.size()); x++) {
                y[x] = oldmap[x];
            }
        }
    }
}
