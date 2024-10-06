#include <raylib.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include "game.hpp"
#include "words.hpp"

int main()
{
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
    std::vector<std::string> &tableWords = *words.ViewWords();

    // Check draw word
    bool draw = false;
    char sign;

    bool gameover = false;

    int life = 7;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        // Convert word to view
        // DrawText(randWord.c_str(), 100, 100, 100, WHITE);

        // Input sign
        if (!gameover)
            sign = game.HandleInput();

        if (!draw)
        {
            randWord = game.DrawWord(tableWords);
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

        if (sign && !tableWords.empty())
        {
            bool checkChance = game.Chance(charArrayWord, sign, sizeWord);

            if (checkChance == 0 && life > 0)
            {
                life--;
            };
        }

        if (life == 0)
            gameover = true;

        if (strcmp(charArrayWord, blackWordsTable) == 0)
            draw = false;
        if (tableWords.empty() && (strcmp(charArrayWord, blackWordsTable) == 0))
            gameover = true;

        // Win Condition
        game.Win(charArrayWord, blackWordsTable, tableWords);
        game.Lose(life);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}