#pragma once
#include <raylib.h>

class Dino
{
public:
    Dino();
    ~Dino();
    void Update();
    void Draw();
    Rectangle GetRect();
    void DrawHitBox(bool isColliding);

private:
    Texture2D image;
    Vector2 position;
    int speed;
};