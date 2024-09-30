#include "game.hpp"
#include "stdlib.h"
#include "time.h"
#include "iostream"

Game::Game()
{
    drawNumber = 0;
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
    // Initialize random seed
    srand(time(NULL));
    drawNumber = rand() % words.size();

    std::cout << drawNumber << std::endl;
    std::cout << words[drawNumber] << std::endl;

    return words[drawNumber];
};
