#include <raylib.h>
#include <chipmunk/chipmunk.h>
#include "player.hpp"

int main()
{
    // Inicjalizacja okna
    InitWindow(800, 600, "My Raylib Game");

    SetTargetFPS(60);

    // Inicijalizacja Chimpunk2D
    cpSpace *space = cpSpaceNew();
    cpVect gravity = cpv(0, 900);
    cpSpaceSetGravity(space, gravity);

    Player player(space);

    // Główna pętla gry
    while (!WindowShouldClose())
    {
        player.HandleInput();
        player.UpdatePhysics(GetFrameTime());
        // Start rysowania
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.DrawPlayer();

        // Koniec rysowania
        EndDrawing();
    }

    cpSpaceFree(space);
    // Zakończenie
    CloseWindow();

    return 0;
}
