#include "dino.hpp"

Dino::Dino()
{
    image = LoadTexture("graphics/dino.png");
    position.x = 100;
    position.y = 100;
    speed = 10;
}

Dino::~Dino()
{
    UnloadTexture(image);
}

void Dino::Draw()
{
    DrawTextureV(image, position, WHITE);
}

void Dino::Update()
{
    if (IsKeyDown(KEY_RIGHT))
        position.x += speed;
    if (IsKeyDown(KEY_LEFT))
        position.x -= speed;
    if (IsKeyDown(KEY_DOWN))
        position.y += speed;
    if (IsKeyDown(KEY_UP))
        position.y -= speed;
}

Rectangle Dino::GetRect()
{
    return Rectangle{position.x, position.y, float(image.width), float(image.height)};
}

void Dino::DrawHitBox(bool isColliding)
{
    Color outlineColor = isColliding ? RED : BLACK;
    DrawRectangleLinesEx(GetRect(), 3, outlineColor);
}
