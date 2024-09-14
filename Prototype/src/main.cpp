#include "raylib.h"

int main()
{
    // Inicjalizacja okna
    InitWindow(800, 600, "My Raylib Game");

    // Główna pętla gry
    while (!WindowShouldClose())
    {
        // Start rysowania
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Tekst do wyświetlenia
        DrawText("Hello, Raylib!", 190, 200, 20, LIGHTGRAY);

        // Koniec rysowania
        EndDrawing();
    }

    // Zakończenie
    CloseWindow();

    return 0;
}
