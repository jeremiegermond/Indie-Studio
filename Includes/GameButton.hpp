/*
** EPITECH PROJECT, 2022
** GameButton.hpp
** File description:
** TODO
*/
#ifndef BOMBERMAN_GAMEBUTTON_HPP
#define BOMBERMAN_GAMEBUTTON_HPP
#include "IObject.hpp"
namespace bomberman {
    class GameButton : public IObject {
    private:
        bool active;
        bool state;
        Texture texture;
    public:
        GameButton(std::string onTexture, std::string offTexure);
        ~GameButton() override;
        void Update();
        void Draw();
    };
}
#endif //BOMBERMAN_GAMEBUTTON_HPP
