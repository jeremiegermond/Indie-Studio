/*
** EPITECH PROJECT, 2022
** IEntity.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_IENTITY_HPP
#define BOMBERMAN_IENTITY_HPP

#pragma once
#include <iostream>

#include "raylib.h"
#include "Objects.hpp"
#include "Logics.hpp"

namespace bomberman {
    class IEntity {
    public:
        virtual ~IEntity() = default;
    };
}
#endif //BOMBERMAN_IENTITY_HPP
