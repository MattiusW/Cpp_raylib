#include <raylib.h>
#include "dino.hpp"

int main()
{
    InitWindow(1200, 800, "Raylib Collsions");
    SetTargetFPS(60);

    Dino dino;
    Rectangle obstacle = Rectangle{800, 200, 200, 175};

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        dino.Update();
        bool isColliding = CheckCollisionRecs(dino.GetRect(), obstacle);
        dino.Draw();
        dino.DrawHitBox(isColliding);
        DrawRectangleLinesEx(obstacle, 5, BLACK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}