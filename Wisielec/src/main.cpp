#include <raylib.h>
#include <vector>
#include <string>
#include <iostream>
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

    // Draw number
    std::string randWord = game.DrawWord(words.ViewWords());

    // Get word Size
    int sizeWord = words.GetWordSize(randWord);

    std::cout << "SIZE: " << sizeWord << std::endl;
    std::cout << "WORD: " << randWord << std::endl;

    // Separate word in table char
    char *charArrayWord = words.GetChars(randWord, sizeWord);

    char *blackWordsTable = words.BlackWords(sizeWord);

    int life = 7;

    for (int i = 0; i < sizeWord; i++)
    {
        std::cout << "Black table: " << blackWordsTable[i] << std::endl;
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        // Convert word to view
        // DrawText(randWord.c_str(), 100, 100, 100, WHITE);
        // Input sign
        char sign = game.HandleInput();
        // Check sign
        char *guestTable = game.CompareWords(charArrayWord, blackWordsTable, sign, sizeWord);

        words.DrawLines(sizeWord, guestTable);

        if (sign)
        {
            bool checkChance = game.Chance(charArrayWord, sign, sizeWord);

            if (checkChance == 0 && life > 0)
            {
                life--;
            };
            std::cout << "Szanse: " << checkChance << std::endl;
            std::cout << "Zycia: " << life << std::endl;
        }

        // std::cout << "Life: " << life << std::endl;

        // Win Condition
        game.Win(charArrayWord, blackWordsTable);

        game.Lose(life);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}