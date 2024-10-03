#include <raylib.h>
#include <vector>
#include <string>
#include <cstring>
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
    std::string randWord;

    // Get word Size
    int sizeWord = 0;

    // Separate word in table char
    char *charArrayWord;
    char *blackWordsTable;

    std::cout << "SIZE: " << sizeWord << std::endl;
    std::cout << "WORD: " << randWord << std::endl;

    // Check draw word
    bool draw = false;
    char sign;

    bool gameover = false;

    int life = 7;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        // Convert word to view
        // DrawText(randWord.c_str(), 100, 100, 100, WHITE);

        // Input sign
        if (!gameover)
            sign = game.HandleInput();

        if (!draw)
        {
            randWord = game.DrawWord(words.ViewWords());
            // Get word Size
            sizeWord = words.GetWordSize(randWord);
            // Separate word in table char
            charArrayWord = words.GetChars(randWord, sizeWord);
            blackWordsTable = words.BlackWords(sizeWord);
            draw = true;
            _sleep(1000); // Wait to another draw
        }
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

        if (life == 0)
            gameover = true;

        // std::cout << "Life: " << life << std::endl;

        // Win Condition
        game.Win(charArrayWord, blackWordsTable);
        game.Lose(life);

        if (strcmp(charArrayWord, blackWordsTable) == 0)
            draw = false;

        EndDrawing();
    }
    CloseWindow();
    return 0;
}