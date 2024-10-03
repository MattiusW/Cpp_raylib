#include "game.hpp"
#include "stdlib.h"
#include "time.h"
#include "iostream"

Game::Game()
{
    drawNumber = 0;
    chance = true;
}

char Game::HandleInput()
{
    char guest = '\0';

    if (IsKeyPressed(KEY_A))
    {
        guest = 'a';
    }
    if (IsKeyPressed(KEY_B))
    {
        guest = 'b';
    }
    if (IsKeyPressed(KEY_C))
    {
        guest = 'c';
    }
    if (IsKeyPressed(KEY_D))
    {
        guest = 'd';
    }
    if (IsKeyPressed(KEY_E))
    {
        guest = 'e';
    }
    if (IsKeyPressed(KEY_F))
    {
        guest = 'f';
    }
    if (IsKeyPressed(KEY_G))
    {
        guest = 'g';
    }
    if (IsKeyPressed(KEY_H))
    {
        guest = 'h';
    }
    if (IsKeyPressed(KEY_I))
    {
        guest = 'i';
    }
    if (IsKeyPressed(KEY_J))
    {
        guest = 'j';
    }
    if (IsKeyPressed(KEY_K))
    {
        guest = 'k';
    }
    if (IsKeyPressed(KEY_L))
    {
        guest = 'l';
    }
    if (IsKeyPressed(KEY_M))
    {
        guest = 'm';
    }
    if (IsKeyPressed(KEY_N))
    {
        guest = 'n';
    }
    if (IsKeyPressed(KEY_O))
    {
        guest = 'o';
    }
    if (IsKeyPressed(KEY_P))
    {
        guest = 'p';
    }
    if (IsKeyPressed(KEY_R))
    {
        guest = 'r';
    }
    if (IsKeyPressed(KEY_S))
    {
        guest = 's';
    }
    if (IsKeyPressed(KEY_T))
    {
        guest = 't';
    }
    if (IsKeyPressed(KEY_U))
    {
        guest = 'u';
    }
    if (IsKeyPressed(KEY_W))
    {
        guest = 'w';
    }
    if (IsKeyPressed(KEY_Y))
    {
        guest = 'y';
    }
    if (IsKeyPressed(KEY_X))
    {
        guest = 'x';
    }
    if (IsKeyPressed(KEY_Z))
    {
        guest = 'z';
    }

    return guest;
}

char *Game::CompareWords(char *guestTable, char *blackTable, char guestSign, int wordSize)
{
    for (int i = 0; i < wordSize; i++)
    {
        if (guestSign == guestTable[i])
            blackTable[i] = guestSign;
    }

    return blackTable;
}

std::string Game::DrawWord(std::vector<std::string> words)
{
    std::string drawnWord;

    if (!words.empty())
    {
        srand(time(NULL)); // Initialize random seed
        drawNumber = rand() % words.size();
        drawnWord = words[drawNumber];
        words.erase(words.begin() + drawNumber);
    }

    std::cout << "WordSize: " << words.size() << std::endl;
    std::cout << words[drawNumber] << std::endl;

    return drawnWord;
};

void Game::Win(char *guestTable, char *blackTable)
{
    if (strcmp(guestTable, blackTable) == 0)
    {
        DrawText("YOU GUEST!", 50, 100, 50, GOLD);
    }
}

void Game::Lose(int life)
{
    if (life == 6)
    {
        DrawText("|", 500, 400, 100, BLACK);
    }
    if (life == 5)
    {
        DrawText("|", 500, 400, 100, BLACK);
        DrawText("|", 500, 450, 100, BLACK);
    }
    if (life == 4)
    {
        DrawText("|", 500, 400, 100, BLACK);
        DrawText("|", 500, 450, 100, BLACK);
        DrawText("-", 470, 390, 100, BLACK);
    }
    if (life == 3)
    {
        DrawText("|", 500, 400, 100, BLACK);
        DrawText("|", 500, 450, 100, BLACK);
        DrawText("-", 470, 390, 100, BLACK);
        DrawText("()", 450, 440, 30, BLACK);
    }
    if (life == 2)
    {
        DrawText("|", 500, 400, 100, BLACK);
        DrawText("|", 500, 450, 100, BLACK);
        DrawText("-", 470, 390, 100, BLACK);
        DrawText("()", 450, 440, 30, BLACK);
        DrawText("|", 460, 470, 30, BLACK);
    }
    if (life == 1)
    {
        DrawText("|", 500, 400, 100, BLACK);
        DrawText("|", 500, 450, 100, BLACK);
        DrawText("-", 470, 390, 100, BLACK);
        DrawText("()", 450, 440, 30, BLACK);
        DrawText("|", 460, 470, 30, BLACK);
        DrawText("/", 450, 470, 30, BLACK);
    }

    if (life == 0)
    {
        DrawText("YOU LOSE!", 5, 200, 50, RED);
        DrawText("|", 500, 400, 100, BLACK);
        DrawText("|", 500, 450, 100, BLACK);
        DrawText("-", 470, 390, 100, BLACK);
        DrawText("()", 450, 440, 30, BLACK);
        DrawText("|", 460, 470, 30, BLACK);
        DrawText("/", 450, 470, 30, BLACK);
        DrawText("/", 450, 479, 30, BLACK);
    }
}

bool Game::Chance(char *guestWord, char guestSign, int wordSize)
{
    for (int i = 0; i < wordSize; i++)
    {
        if (guestSign == guestWord[i])
        {
            return true;
        }
    }

    return false;
}
