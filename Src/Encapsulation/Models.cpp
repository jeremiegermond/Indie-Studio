/*
** EPITECH PROJECT, 2022
** Models.cpp
** File description:
** TODO
*/

#include "Models.hpp"

namespace bomberman {
    inline void drawLine3D(const MyVector3 &startPos, const MyVector3 &endPos, const MyColor &color) {
        DrawLine3D(startPos, endPos, color);
    }
    
    inline void drawPoint3D(const MyVector3 &position, const MyColor &color) {
        DrawPoint3D(position, color);
    }
    
    inline void drawCircle3D(const MyVector3 &center, const float &radius, const MyVector3 &rotationAxis, const float &rotationAngle, const MyColor &color) {
        DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);
    }
    
    inline void drawTriangle3D(const MyVector3 &v1, const MyVector3 &v2, const MyVector3 &v3, const MyColor &color) {
        DrawTriangle3D(v1, v2, v3, color);
    }
    
    inline void drawTriangleStrip3D(MyVector3 *points, const int &pointsCount, const MyColor &color) {
        DrawTriangleStrip3D(points, pointsCount, color);
    }
    
    inline void drawCube(const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCube(position, width, height, length, color);
    }
    
    inline void drawCubeV(const MyVector3 &position, const MyVector3 &size, const MyColor &color) {
        DrawCubeV(position, size, color);
    }
    
    inline void drawCubeWires(const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCubeWires(position, width, height, length, color);
    }
    
    inline void drawCubeWiresV(const MyVector3 &position, const MyVector3 &size, const MyColor &color) {
        DrawCubeWiresV(position, size, color);
    }
    
    inline void drawCubeTexture(const MyTexture &texture, const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCubeTexture(texture, position, width, height, length, color);
    }
    
    inline void drawCubeTextureRec(const MyTexture &texture, const MyRectangle &source, const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCubeTextureRec(texture, source, position, width, height, length, color);
    }
    
    inline void drawSphere(const MyVector3 &centerPos, const float &radius, const MyColor &color) {
        DrawSphere(centerPos, radius, color);
    }
    
    inline void drawSphereEx(const MyVector3 &centerPos, const float &radius, const int &rings, const int &slices, const MyColor &color) {
        DrawSphereEx(centerPos, radius, rings, slices, color);
    }
    
    inline void drawSphereWires(const MyVector3 &centerPos, const float &radius, const int &rings, const int &slices, const MyColor &color) {
        DrawSphereWires(centerPos, radius, rings, slices, color);
    }
    
    inline void drawCylinder(const MyVector3 &position, const float &radiusTop, const float &radiusBottom, const float &height, const int &slices, const MyColor &color) {
        DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
    }
    
    inline void drawCylinderEx(const MyVector3 &startPos, const MyVector3 &endPos, const float &startRadius, const float &endRadius, const int &sides, const MyColor &color) {
        DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color);
    }
    
    inline void drawCylinderWires(const MyVector3 &position, const float &radiusTop, const float &radiusBottom, const float &height, const int &slices, const MyColor &color) {
        DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
    }
    
    inline void drawCylinderWiresEx(const MyVector3 &startPos, const MyVector3 &endPos, const float &startRadius, const float &endRadius, const int &sides, const MyColor &color) {
        DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, color);
    }
    
    inline void drawPlane(const MyVector3 &centerPos, const MyVector2 &size, const MyColor &color) {
        DrawPlane(centerPos, size, color);
    }
    
    inline void drawRay(const MyRay &ray, const MyColor &color) {
        DrawRay(ray, color);
    }
    
    inline void drawGrid(const int &slices, const float &spacing) {
        DrawGrid(slices, spacing);
    }
    
}