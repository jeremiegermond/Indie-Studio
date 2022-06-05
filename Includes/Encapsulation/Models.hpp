/*
** EPITECH PROJECT, 2022
** Models.hpp
** File description:
** TODO
*/

#include "raylib.h"
#include "Objects.hpp"
#include "Color.hpp"

namespace bomberman {
    class Models {
    public:
        // Basic geometric 3D shapes drawing functions
        Models() {}
        ~Models() {}

        // Draw a line in 3D world space
        inline void drawLine3D(const MyVector3 &startPos, const MyVector3 &endPos, const MyColor &color);

        // Draw a point in 3D space, actually a small line
        inline void drawPoint3D(const MyVector3 &position, const MyColor &color);

        // Draw a circle in 3D world space
        inline void drawCircle3D(const MyVector3 &center, const float &radius, const MyVector3 &rotationAxis, const float &rotationAngle, const MyColor &color);

        // Draw a color-filled triangle (vertex in counter-clockwise order!)
        inline void drawTriangle3D(const MyVector3 &v1, const MyVector3 &v2, const MyVector3 &v3, const MyColor &color);

        // Draw a triangle strip defined by points
        inline void drawTriangleStrip3D(MyVector3 *points, const int &pointsCount, const MyColor &color);

        // Draw cube
        inline void drawCube(const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color);

        // Draw cube (Vector version)
        inline void drawCubeV(const MyVector3 &position, const MyVector3 &size, const MyColor &color);

        // Draw cube wires
        inline void drawCubeWires(const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color);

        // Draw cube wires (Vector version)
        inline void drawCubeWiresV(const MyVector3 &position, const MyVector3 &size, const MyColor &color);

        // Draw cube textured
        inline void drawCubeTexture(const MyTexture &texture, const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color);

        // Draw cube with a region of a texture
        inline void drawCubeTextureRec(const MyTexture &texture, const MyRectangle &source, const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color);

        // Draw sphere
        inline void drawSphere(const MyVector3 &centerPos, const float &radius, const MyColor &color);

        // Draw sphere with extended parameters
        inline void drawSphereEx(const MyVector3 &centerPos, const float &radius, const int &rings, const int &slices, const MyColor &color);

        // Draw sphere wires
        inline void drawSphereWires(const MyVector3 &centerPos, const float &radius, const int &rings, const int &slices, const MyColor &color);

        // Draw a cylinder/cone
        inline void drawCylinder(const MyVector3 &position, const float &radiusTop, const float &radiusBottom, const float &height, const int &slices, const MyColor &color);

        // Draw a cylinder with base at startPos and top at endPos
        inline void drawCylinderEx(const MyVector3 &startPos, const MyVector3 &endPos, const float &startRadius, const float &endRadius, const int &sides, const MyColor &color);

        // Draw a cylinder/cone wires
        inline void drawCylinderWires(const MyVector3 &position, const float &radiusTop, const float &radiusBottom, const float &height, const int &slices, const MyColor &color);

        // Draw a cylinder wires with base at startPos and top at endPos
        inline void drawCylinderWiresEx(const MyVector3 &startPos, const MyVector3 &endPos, const float &startRadius, const float &endRadius, const int &sides, const MyColor &color);

        // Draw a plane XZ
        inline void drawPlane(const MyVector3 &centerPos, const MyVector2 &size, const MyColor &color);

        // Draw a ray line
        inline void drawRay(const MyRay &ray, const MyColor &color);

        // Draw a grid (centered at (0, 0, 0))
        inline void drawGrid(const int &slices, const float &spacing);
    };
}

