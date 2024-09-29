#include "game.hpp"
#include "stdlib.h"
#include "time.h"
#include "iostream"

Game::Game()
{
    drawNumber = 0;
}

bool Game::CompareWords()
{   
    

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

