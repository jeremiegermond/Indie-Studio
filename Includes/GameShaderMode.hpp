/*
** EPITECH PROJECT, 2022
** GameShaderMode.hpp
** File description:
** GameShaderMode
*/

#ifndef GAMESHADERMODE_HPP_
#define GAMESHADERMODE_HPP_

#include "IEntity.hpp"
#include "Color.hpp"

namespace bomberman {
    class GameShaderMode : public IEntity {
        private:
            Image _imageLightmode;
            Image _imageDarkmode;
            Texture2D _textureLightmode;
            Texture2D _textureDarkmode;
            MyColor _color;
            MyVector2 _position;
            bool active{};
            bool darkmode = true;
        
        public:
            GameShaderMode(const std::string &darkmode, const std::string &lightmode, float x, float y, MyColor color);
            ~GameShaderMode() override = default;
            void Draw();

            void Update() {}
            void Reset() {}
            void SetActive(bool activate);
            void Move(MyVector3 velocity) {
                (void) velocity;
            }
    };
}


#endif /* !GAMESHADERMODE_HPP_ */
