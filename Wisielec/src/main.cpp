#include <raylib.h>
#include <vector>
#include <string>
#include "game.hpp"
#include "words.hpp"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    Game game = Game();
    Words words = Words();

    game.DrawWord(words.ViewWords());

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}