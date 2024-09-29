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
    char guest = '?';

    if (IsKeyPressed(KEY_A))
        guest = 'a';
    if (IsKeyPressed(KEY_E))
        guest = 'e';
    if (IsKeyPressed(KEY_O))
        guest = 'o';

    return guest;
}

bool Game::CompareWords(char *guestWord, char guestSign, int wordSize)
{
    for (int i = 0; i < wordSize; i++)
    {
        if (guestSign == guestWord[i])
            return true;
    }

    return false;
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
