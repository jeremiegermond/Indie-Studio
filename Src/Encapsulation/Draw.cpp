/*
** EPITECH PROJECT, 2022
** Draw.cpp
** File description:
** TODO
*/

#include "Draw.hpp"
#include "Color.hpp"
#include "raymath.h"
#include "rlgl.h"

namespace bomberman {
    void Draw::clearBackground(const MyColor &color) {
        return ClearBackground(color);
    }
    
    void Draw::beginDrawing(void) {
        return BeginDrawing();
    }
    
    void Draw::endDrawing(void) {
        return EndDrawing();
    }
    
    void Draw::beginMode2D(const MyCamera2D &camera) {
        return BeginMode2D(camera);
    }
    
    void Draw::endMode2D(void) {
        return EndMode2D();
    }
    
    void Draw::beginMode3D(const MyCamera &camera) {
        return BeginMode3D(camera);
    }
    
    void Draw::endMode3D(void) {
        return EndMode3D();
    }
    
    void Draw::beginTextureMode(const RenderTexture2D &target) {
        return BeginTextureMode(target);
    }
    
    void Draw::endTextureMode(void) {
        return EndTextureMode();
    }
    
    void Draw::beginShaderMode(const Shader &shader) {
        return BeginShaderMode(shader);
    }
    
    void Draw::endShaderMode(void) {
        return EndShaderMode();
    }

    void Draw::drawLine3D(const MyVector3 &startPos, const MyVector3 &endPos, const MyColor &color) {
        DrawLine3D(startPos, endPos, color);
    }

    void Draw::drawPoint3D(const MyVector3 &position, const MyColor &color) {
        return DrawPoint3D(position, color);
    }
    
    void Draw::drawCircle3D(const MyVector3 &center, const float &radius, const MyVector3 &rotationAxis, const float &rotationAngle, const MyColor &color) {
        return DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);
    }

    void Draw::drawTriangle3D(const MyVector3 &v1, const MyVector3 &v2, const MyVector3 &v3, const MyColor &color) {
        DrawTriangle3D(v1, v2, v3, color);
    }

    void Draw::drawCube(const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCube(position, width, height, length, color);
    }

    void Draw::drawCubeV(const MyVector3 &position, const MyVector3 &size, const MyColor &color) {
        DrawCubeV(position, size, color);
    }

    void Draw::drawCubeWires(const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCubeWires(position, width, height, length, color);
    }

    void Draw::drawCubeWiresV(const MyVector3 &position, const MyVector3 &size, const MyColor &color) {
        DrawCubeWiresV(position, size, color);
    }

    void Draw::drawCubeTexture(const Texture2D &texture, const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCubeTexture(texture, position, width, height, length, color);
    }

    void Draw::drawCubeTextureRec(const MyTexture &texture, const MyRectangle &source, const MyVector3 &position, const float &width, const float &height, const float &length, const MyColor &color) {
        DrawCubeTextureRec(texture, source, position, width, height, length, color);
    }

    void Draw::drawSphere(const MyVector3 &centerPos, const float &radius, const MyColor &color) {
        DrawSphere(centerPos, radius, color);
    }

    void Draw::drawSphereEx(const MyVector3 &centerPos, const float &radius, const int &rings, const int &slices, const MyColor &color) {
        DrawSphereEx(centerPos, radius, rings, slices, color);
    }

    void Draw::drawSphereWires(const MyVector3 &centerPos, const float &radius, const int &rings, const int &slices, const MyColor &color) {
        DrawSphereWires(centerPos, radius, rings, slices, color);
    }

    void Draw::drawCylinder(const MyVector3 &position, const float &radiusTop, const float &radiusBottom, const float &height, const int &slices, const MyColor &color) {
        DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
    }

    void Draw::drawCylinderEx(const MyVector3 &startPos, const MyVector3 &endPos, const float &startRadius, const float &endRadius, const int &sides, const MyColor &color) {
        DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color);
    }

    void Draw::drawCylinderWires(const MyVector3 &position, const float &radiusTop, const float &radiusBottom, const float &height, int slices, const MyColor &color) {
        DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
    }

    void Draw::drawCylinderWiresEx(const MyVector3 &startPos, const MyVector3 &endPos, const float &startRadius, const float &endRadius, const int &sides, const MyColor &color) {
        DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, color);
    }

    void Draw::drawPlane(const MyVector3 &centerPos, const MyVector2 &size, const MyColor &color) {
        DrawPlane(centerPos, size, color);
    }

    void Draw::drawRay(const MyRay &ray, const MyColor &color) {
        DrawRay(ray, color);
    }

    void Draw::drawGrid(const int &slices, const float &spacing) {
        DrawGrid(slices, spacing);
    }

    void Draw::drawTextureRec(Texture2D texture, MyRectangle source, MyVector2 position, MyColor tint) {
        return DrawTextureRec(texture, source, position, tint);
    }

    void Draw::drawTextEx(Font font, const char *text, MyVector2 position, float fontSize, float spacing, MyColor tint) {
        return DrawTextEx(font, text, position, fontSize, spacing, tint);
    }

    void Draw::drawTexture(Texture2D texture, int posX, int posY, MyColor tint) {
        return DrawTexture(texture, posX, posY, tint);
    }

    void Draw::drawModel(Model model, MyVector3 position, float scale, MyColor tint) {
        return DrawModel(model, position, scale, tint);
    }

    void Draw::draw3DBillboardRec(MyCamera camera, Texture2D texture, MyRectangle source, Vector3 position, MyVector2 size, MyColor tint) {
        rlPushMatrix();

        // get the camera view matrix
        Matrix mat = MatrixInvert(MatrixLookAt(camera.position, camera.target, camera.up));
        // peel off just the rotation
        Quaternion quat = QuaternionFromMatrix(mat);
        mat = QuaternionToMatrix(quat);

        // apply just the rotation
        rlMultMatrixf(MatrixToFloat(mat));

        // translate backwards in the inverse rotated matrix to put the item where it goes in world space
        auto vector3 = Vector3Transform(position, MatrixInvert(mat));
        position.x = vector3.x;
        position.y = vector3.y;
        position.z = vector3.z;
        rlTranslatef(position.x, position.y, position.z);

        // draw the billboard
        float width = size.x / 2;
        float height = size.y / 2;

        rlCheckRenderBatchLimit(6);

        rlSetTexture(texture.id);

        // draw quad
        rlBegin(RL_QUADS);
        rlColor4ub(tint.r, tint.g, tint.b, tint.a);
        // Front Face
        rlNormal3f(0.0f, 0.0f, 1.0f);                  // Normal Pointing Towards Viewer

        rlTexCoord2f(float(source.x / texture.width), float((source.y + source.height) / texture.height));
        rlVertex3f(-width, -height, 0);  // Bottom Left Of The Texture and Quad

        rlTexCoord2f((float)(source.x + source.width) / texture.width, (float)(source.y + source.height) / texture.height);
        rlVertex3f(+width, -height, 0);  // Bottom Right Of The Texture and Quad

        rlTexCoord2f((float)(source.x + source.width) / texture.width, (float)source.y / texture.height);
        rlVertex3f(+width, +height, 0);  // Top Right Of The Texture and Quad

        rlTexCoord2f((float)source.x / texture.width, (float)source.y / texture.height);
        rlVertex3f(-width, +height, 0);  // Top Left Of The Texture and Quad

        rlEnd();
        rlSetTexture(0);
        rlPopMatrix();
    }

    void Draw::draw3DBillboard(MyCamera camera, Texture2D texture, Vector3 position, float size,
                               MyColor tint) {
        draw3DBillboardRec(camera, texture, {0, 0, (float) texture.width, (float) texture.height}, position,
                           {size, size}, tint);
    }


    void Draw::draw(const std::function<void()> &function) {
        beginDrawing();
        function();
        endDrawing();
    }

    void Draw::mode2D(const MyCamera2D &camera, const std::function<void()> &function) {
        beginMode2D(camera);
        function();
        endMode2D();
    }

    void Draw::mode3D(const MyCamera &camera, const std::function<void()> &function) {
        beginMode3D(camera);
        function();
        endMode3D();
    }

    void Draw::textureMode(const RenderTexture2D &texture, const std::function<void()> &function) {
        beginTextureMode(texture);
        function();
        endTextureMode();
    }

    void Draw::shaderMode(const MyShader &shader, const std::function<void()> &function) {
        beginShaderMode(shader);
        function();
        endShaderMode();
    }
}