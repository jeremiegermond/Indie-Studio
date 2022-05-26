/*
** EPITECH PROJECT, 2022
** Object.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_IOBJECT_HPP
#define BOMBERMAN_IOBJECT_HPP

#include "IEntity.hpp"

namespace bomberman {
    class IObject : public IEntity {
    public:
        ~IObject() override = default;

        virtual void Draw() = 0;

        virtual void SetPosition(Vector3 position) = 0;

        virtual void SetAnimation(int newSelectedAnimation) = 0;
    };
}
#endif //BOMBERMAN_IOBJECT_HPP
