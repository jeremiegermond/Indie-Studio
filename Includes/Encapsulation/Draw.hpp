/*
** EPITECH PROJECT, 2022
** Draw.hpp
** File description:
** TODO
*/

#pragma once

#include "raylib.h"
#include <functional>
#include <iostream>
#include "Objects.hpp"
#include "Color.hpp"

namespace bomberman {
    class Draw {
    public:
        Draw() = delete;
        virtual ~Draw() = delete;
        // Set background color (framebuffer clear color)
        static inline void clearBackground(const MyColor &color);

        // Setup canvas (framebuffer) to start drawing
        static inline void beginDrawing(void);

        // End canvas drawing and swap buffers (double buffering)
        static inline void endDrawing(void);

        // Begin 2D mode with custom camera (2D)
        static inline void beginMode2D(const MyCamera2D &camera);

        // Ends 2D mode with custom camera
        static inline void endMode2D(void);

        // Begin 3D mode with custom camera (3D)
        static inline void beginMode3D(const MyCamera &camera);

        // Ends 3D mode and returns to default 2D orthographic mode
        static inline void endMode3D(void);

        // Begin drawing to render texture
        static inline void beginTextureMode(const RenderTexture2D &target);

        // Ends drawing to render texture
        static inline void endTextureMode(void);

        // Begin custom shader drawing
        static inline void beginShaderMode(const MyShader &shader);

        // End custom shader drawing (use default shader)
        static inline void endShaderMode(void);

        // Draw functions
        // Draw a line in 3D world space
        static inline void drawLine3D(const MyVector3 &startPos, const MyVector3 &endPos, const MyColor &color);

        // Draw a point in 3D space, actually a small line
        static inline void drawPoint3D(const MyVector3 &position, const MyColor &color);

        // Draw a circle in 3D world space
        static inline void drawCircle3D(const MyVector3 &center, const float &radius, const MyVector3 &rotationAxis, const float &rotationAngle, const MyColor &color);

        // Draw a color-filled triangle (vertex in counter-clockwise order!)
        static inline void drawTriangle3D(const MyVector3 &v1, const MyVector3 &v2, const MyVector3 &v3, const MyColor &color);

        // Draw cube
        static inline void drawCube(const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color);

        // Draw cube (Vector version)
        static inline void drawCubeV(const MyVector3 &position, const MyVector3 &size, const MyColor &color);

        // Draw cube wires
        static inline void drawCubeWires(const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color);

        // Draw cube wires (Vector version)
        static inline void drawCubeWiresV(const MyVector3 &position, const MyVector3 &size, const MyColor &color);

        // Draw cube textured
        static inline void drawCubeTexture(const Texture2D &texture, const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color);

        // Draw cube with a region of a texture
        static inline void drawCubeTextureRec(const MyTexture &texture, const MyRectangle &source, const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color);

        // Draw sphere
        static inline void drawSphere(const MyVector3 &centerPos, const float &radius, const MyColor &color);

        // Draw sphere with extended parameters
        static inline void drawSphereEx(const MyVector3 &centerPos, const float &radius, const int &rings, const int &slices, const MyColor &color);

        // Draw sphere wires
        static inline void drawSphereWires(const MyVector3 &centerPos, const float &radius, const int &rings, const int &slices, const MyColor &color);

        // Draw a cylinder/cone
        static inline void drawCylinder(const MyVector3 &position, const float &radiusTop, const float &radiusBottom, const float &height, const int &slices, const MyColor &color);

        // Draw a cylinder with base at startPos and top at endPos
        static inline void drawCylinderEx(const MyVector3 &startPos, const MyVector3 &endPos, const float &startRadius, const float &endRadius, const int &sides, const MyColor &color);

        // Draw a cylinder/cone wires
        static inline void drawCylinderWires(const MyVector3 &position, const float &radiusTop, const float &radiusBottom, const float &height, int slices, const MyColor &color);

        // Draw a cylinder wires with base at startPos and top at endPos
        static inline void drawCylinderWiresEx(const MyVector3 &startPos, const MyVector3 &endPos, const float &startRadius, const float &endRadius, const int &sides, const MyColor &color);

        // Draw a plane XZ
        static inline void drawPlane(const MyVector3 &centerPos, const MyVector2 &size, const MyColor &color);

        // Draw a ray line
        static inline void drawRay(const MyRay &ray, const MyColor &color);

        // Draw a grid (centered at (0, 0, 0))
        static inline void drawGrid(const int &slices, const float &spacing);

        //additional function: draw
        static inline void draw(const std::function<void()> &function);

        //additional function: mode2D
        static inline void mode2D(const MyCamera2D &camera, const std::function<void()> &function);

        //additional function: mode3D
        static void mode3D(const MyCamera &camera, const std::function<void()> &function);

        //additional function: textureMode
        static inline void textureMode(const RenderTexture2D &texture, const std::function<void()> &function);

        //additional function: shaderMode
        static inline void shaderMode(const MyShader &shader, const std::function<void()> &function);
    };
}
