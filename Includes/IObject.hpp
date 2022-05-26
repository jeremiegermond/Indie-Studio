/*
** EPITECH PROJECT, 2022
** Object.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_IOBJECT_HPP
#define BOMBERMAN_IOBJECT_HPP

namespace bomberman {
    class IObject {
    public:
        virtual ~IObject() = default;

        virtual void Draw() = 0;

        virtual void Update() = 0;

        virtual void SetPosition(Vector3 position) = 0;

        virtual void SetAnimation(int newSelectedAnimation) = 0;

        virtual void SetActive(bool activate) = 0;

        virtual void Move(Vector3 velocity) = 0;
    };
}
#endif //BOMBERMAN_IOBJECT_HPP
