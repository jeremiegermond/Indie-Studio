/*
** EPITECH PROJECT, 2022
** Draw.cpp
** File description:
** TODO
*/

#include "Draw.hpp"
#include "Color.hpp"

namespace bomberman {
    inline void Draw::clearBackground(const MyColor &color) {
        return ClearBackground(color);
    }
    
    inline void Draw::beginDrawing(void) {
        return BeginDrawing();
    }
    
    inline void Draw::endDrawing(void) {
        return EndDrawing();
    }
    
    inline void Draw::beginMode2D(const MyCamera2D &camera) {
        return BeginMode2D(camera);
    }
    
    inline void Draw::endMode2D(void) {
        return EndMode2D();
    }
    
    inline void Draw::beginMode3D(const MyCamera &camera) {
        return BeginMode3D(camera);
    }
    
    inline void Draw::endMode3D(void) {
        return EndMode3D();
    }
    
    inline void Draw::beginTextureMode(const RenderTexture2D &target) {
        return BeginTextureMode(target);
    }
    
    inline void Draw::endTextureMode(void) {
        return EndTextureMode();
    }
    
    inline void Draw::beginShaderMode(const MyShader &shader) {
        return BeginShaderMode(shader);
    }
    
    inline void Draw::endShaderMode(void) {
        return EndShaderMode();
    }

    inline void Draw::drawLine3D(const MyVector3 &startPos, const MyVector3 &endPos, const MyColor &color) {
        DrawLine3D(startPos, endPos, color);
    }

    inline void Draw::drawPoint3D(const MyVector3 &position, const MyColor &color) {
        return DrawPoint3D(position, color);
    }
    
    inline void Draw::drawCircle3D(const MyVector3 &center, const float &radius, const MyVector3 &rotationAxis, const float &rotationAngle, const MyColor &color) {
        return DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);
    }

    inline void Draw::drawTriangle3D(const MyVector3 &v1, const MyVector3 &v2, const MyVector3 &v3, const MyColor &color) {
        DrawTriangle3D(v1, v2, v3, color);
    }

    inline void Draw::drawCube(const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCube(position, width, height, length, color);
    }

    inline void Draw::drawCubeV(const MyVector3 &position, const MyVector3 &size, const MyColor &color) {
        DrawCubeV(position, size, color);
    }

    inline void Draw::drawCubeWires(const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCubeWires(position, width, height, length, color);
    }

    inline void Draw::drawCubeWiresV(const MyVector3 &position, const MyVector3 &size, const MyColor &color) {
        DrawCubeWiresV(position, size, color);
    }

    inline void Draw::drawCubeTexture(const Texture2D &texture, const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCubeTexture(texture, position, width, height, length, color);
    }

    inline void Draw::drawCubeTextureRec(const MyTexture &texture, const MyRectangle &source, const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCubeTextureRec(texture, source, position, width, height, length, color);
    }

    inline void Draw::drawSphere(const MyVector3 &centerPos, const float &radius, const MyColor &color) {
        DrawSphere(centerPos, radius, color);
    }

    inline void Draw::drawSphereEx(const MyVector3 &centerPos, const float &radius, const int &rings, const int &slices, const MyColor &color) {
        DrawSphereEx(centerPos, radius, rings, slices, color);
    }

    inline void Draw::drawSphereWires(const MyVector3 &centerPos, const float &radius, const int &rings, const int &slices, const MyColor &color) {
        DrawSphereWires(centerPos, radius, rings, slices, color);
    }

    inline void Draw::drawCylinder(const MyVector3 &position, const float &radiusTop, const float &radiusBottom, const float &height, const int &slices, const MyColor &color) {
        DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
    }

    inline void Draw::drawCylinderEx(const MyVector3 &startPos, const MyVector3 &endPos, const float &startRadius, const float &endRadius, const int &sides, const MyColor &color) {
        DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color);
    }

    inline void Draw::drawCylinderWires(const MyVector3 &position, const float &radiusTop, const float &radiusBottom, const float &height, int slices, const MyColor &color) {
        DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
    }

    inline void Draw::drawCylinderWiresEx(const MyVector3 &startPos, const MyVector3 &endPos, const float &startRadius, const float &endRadius, const int &sides, const MyColor &color) {
        DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, color);
    }

    inline void Draw::drawPlane(const MyVector3 &centerPos, const MyVector2 &size, const MyColor &color) {
        DrawPlane(centerPos, size, color);
    }

    inline void Draw::drawRay(const MyRay &ray, const MyColor &color) {
        DrawRay(ray, color);
    }

    inline void Draw::drawGrid(const int &slices, const float &spacing) {
        DrawGrid(slices, spacing);
    }

    inline void Draw::draw(const std::function<void()> &function) {
        beginDrawing();
        function();
        endDrawing();
    }

    inline void Draw::mode2D(const MyCamera2D &camera, const std::function<void()> &function) {
        beginMode2D(camera);
        function();
        endMode2D();
    }

    inline void Draw::mode3D(const MyCamera &camera, const std::function<void()> &function) {
        beginMode3D(camera);
        function();
        endMode3D();
    }

    inline void Draw::textureMode(const RenderTexture2D &texture, const std::function<void()> &function) {
        beginTextureMode(texture);
        function();
        endTextureMode();
    }

    inline void Draw::shaderMode(const MyShader &shader, const std::function<void()> &function) {
        beginShaderMode(shader);
        function();
        endShaderMode();
    }
}