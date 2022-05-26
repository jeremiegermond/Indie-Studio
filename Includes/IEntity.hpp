/*
** EPITECH PROJECT, 2022
** IEntity.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_IENTITY_HPP
#define BOMBERMAN_IENTITY_HPP

#include <iostream>

#include "raylib.h"

namespace bomberman {
    class IEntity {
    public:
        virtual ~IEntity() = default;

        virtual void Update() = 0;

        virtual void Reset() = 0;

        virtual void SetActive(bool activate) = 0;

        virtual void Move(Vector3 velocity) = 0;
    };
}
#endif //BOMBERMAN_IENTITY_HPP
