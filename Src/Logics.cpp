/*
** EPITECH PROJECT, 2022
** Logics.cpp
** File description:
** TODO
*/

#include "Logics.hpp"

namespace bomberman {
    Matrix MatrixRotateXYZ(Vector3 ang)
    {

        Matrix result = { 1.0f, 0.0f, 0.0f, 0.0f,

                          0.0f, 1.0f, 0.0f, 0.0f,

                          0.0f, 0.0f, 1.0f, 0.0f,

                          0.0f, 0.0f, 0.0f, 1.0f }; // MatrixIdentity()

        Vector3 cos {cosf(-ang.x), cosf(-ang.y), cosf(-ang.z)};
        Vector3 sin {sinf(-ang.x), sinf(-ang.y), sinf(-ang.z)};


        result.m0 = cos.z*cos.y;

        result.m4 = (cos.z*sin.y*sin.x) - (sin.z*cos.x);

        result.m8 = (cos.z*sin.y*cos.x) + (sin.z*sin.x);


        result.m1 = sin.z*cos.y;

        result.m5 = (sin.z*sin.y*sin.x) + (cos.z*cos.x);

        result.m9 = (sin.z*sin.y*cos.x) - (cos.z*sin.x);


        result.m2 = -sin.y;

        result.m6 = cos.y*sin.x;

        result.m10= cos.y*cos.x;


        return result;

    }
}