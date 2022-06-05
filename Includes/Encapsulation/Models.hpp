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
        Models();
        ~Models();

        // Draw a line in 3D world space
        inline void drawLine3D(MyVector3 startPos, MyVector3 endPos, MyColor color);

        // Draw a point in 3D space, actually a small line
        inline void drawPoint3D(MyVector3 position, MyColor color);

        // Draw a circle in 3D world space
        inline void drawCircle3D(MyVector3 center, float radius, MyVector3 rotationAxis, float rotationAngle, MyColor color);

        // Draw a color-filled triangle (vertex in counter-clockwise order!)
        inline void drawTriangle3D(MyVector3 v1, MyVector3 v2, MyVector3 v3, MyColor color);

        // Draw a triangle strip defined by points
        inline void drawTriangleStrip3D(MyVector3 *points, int pointsCount, MyColor color);

        // Draw cube
        inline void drawCube(MyVector3 position, float width, float height, float length, MyColor color);

        // Draw cube (Vector version)
        inline void drawCubeV(MyVector3 position, MyVector3 size, MyColor color);

        // Draw cube wires
        inline void drawCubeWires(MyVector3 position, float width, float height, float length, MyColor color);

        // Draw cube wires (Vector version)
        inline void drawCubeWiresV(MyVector3 position, MyVector3 size, MyColor color);

        // Draw cube textured
        inline void drawCubeTexture(MyTexture texture, MyVector3 position, float width, float height, float length, MyColor color);

        // Draw cube with a region of a texture
        inline void drawCubeTextureRec(MyTexture texture, MyRectangle source, MyVector3 position, float width, float height, float length, MyColor color);

        // Draw sphere
        inline void drawSphere(MyVector3 centerPos, float radius, MyColor color);

        // Draw sphere with extended parameters
        inline void drawSphereEx(MyVector3 centerPos, float radius, int rings, int slices, MyColor color);

        // Draw sphere wires
        inline void drawSphereWires(MyVector3 centerPos, float radius, int rings, int slices, MyColor color);

        // Draw a cylinder/cone
        inline void drawCylinder(MyVector3 position, float radiusTop, float radiusBottom, float height, int slices, MyColor color);

        // Draw a cylinder with base at startPos and top at endPos
        inline void drawCylinderEx(MyVector3 startPos, MyVector3 endPos, float startRadius, float endRadius, int sides, MyColor color);

        // Draw a cylinder/cone wires
        inline void drawCylinderWires(MyVector3 position, float radiusTop, float radiusBottom, float height, int slices, MyColor color);

        // Draw a cylinder wires with base at startPos and top at endPos
        inline void drawCylinderWiresEx(MyVector3 startPos, MyVector3 endPos, float startRadius, float endRadius, int sides, MyColor color);

        // Draw a plane XZ
        inline void drawPlane(MyVector3 centerPos, MyVector2 size, MyColor color);

        // Draw a ray line
        inline void drawRay(MyRay ray, MyColor color);

        // Draw a grid (centered at (0, 0, 0))
        inline void drawGrid(int slices, float spacing);
    };
}

