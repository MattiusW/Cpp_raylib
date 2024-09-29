#include "words.hpp"
#include "iostream"

Words::Words()
{
    words = {"cat", "dog", "turtle", "koala"};
    position.x = 300;
    position.y = 300;
}

std::vector<std::string> Words::ViewWords()
{
    return words;
}

int Words::GetWordSize(std::string word)
{
    return word.size();
}

void Words::DrawLines(int wordSize)
{
    int space = 0;
    for (int i = 0; i < wordSize; i++)
    {
        DrawText("_", position.x + space, position.y, 50, WHITE);
        space += 70;
    }
}

char *Words::GetChars(std::string word, int wordSize)
{
    char *wordArray = new char[wordSize];

    for (int i = 0; i < wordSize; i++)
    {
        std::cout << word[i] << std::endl;
        wordArray[i] = word[i];
    }

    return wordArray;
}
