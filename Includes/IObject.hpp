/*
** EPITECH PROJECT, 2022
** Object.hpp
** File description:
** TODO
*/

#pragma once

#include "IEntity.hpp"
#include "Objects.hpp"

namespace bomberman {
    class IObject : public IEntity {
    public:
        ~IObject() override = default;

        virtual void Draw() = 0;

        virtual void SetPosition(MyVector3 position) = 0;

        virtual void SetAnimation(int newSelectedAnimation) = 0;
    };
}
