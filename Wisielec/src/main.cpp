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
    int tableSize = 0;

    // Separate word in table char
    char *charArrayWord;
    char *blackWordsTable;
    std::vector<std::string> &tableWords = *words.ViewWords();

    char viewLetter[2];
    char showSize[2];

    // Check draw word
    bool draw = false;

    int rare = 1;
    char showRare[2];

    // check input
    bool input = false;
    char sign;

    bool gameover = false;

    int life = 7;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        // Convert word to view
        // DrawText(randWord.c_str(), 100, 100, 100, WHITE);

        DrawText("WORDS:", 650, 10, 20, WHITE);

        // Input sign
        if (!gameover)
            sign = game.HandleInput();

        if (!draw)
        {
            randWord = game.DrawWord(tableWords);
            // Get word Size
            sizeWord = words.GetWordSize(randWord);
            tableSize = tableWords.size();
            // Show word Size
            sprintf(showSize, "%d", tableSize);
            showSize[1] = '\0';
            // Separate word in table char
            charArrayWord = words.GetChars(randWord, sizeWord);
            blackWordsTable = words.BlackWords(sizeWord);
            draw = true;
            _sleep(1000); // Wait to another draw
        }
        // Check sign
        char *guestTable = game.CompareWords(charArrayWord, blackWordsTable, sign, sizeWord);

        words.DrawLines(sizeWord, guestTable);

        if (sign && !gameover)
        {
            bool checkChance = game.Chance(charArrayWord, sign, sizeWord);

            if (checkChance == 0 && life > 0)
            {
                life--;
            };
            // convert char to view
            viewLetter[0] = sign;
            viewLetter[1] = '\0'; // Show input letter

            input = true;
        }

        if (life == 0)
            gameover = true;

        if (strcmp(charArrayWord, blackWordsTable) == 0)
        {
            rare = words.EndRare(tableSize);
            draw = false;
            input = false;
        }

        if (tableWords.empty() && (strcmp(charArrayWord, blackWordsTable) == 0))
            gameover = true;

        // Win Condition
        game.Win(charArrayWord, blackWordsTable, tableWords);
        game.Lose(life);

        if (input)
            DrawText(viewLetter, 350, 50, 100, GREEN);
        if (!input && !gameover)
            DrawText("Press key!", 150, 70, 70, GREEN);

        DrawText(showSize, 750, 10, 20, WHITE);

        if (gameover)
        {
            sprintf(showRare, "%d", rare);
            showRare[1] = '\0';
            DrawText("Rare: ", 40, 50, 50, GOLD);
            DrawText(showRare, 200, 50, 50, GOLD);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}