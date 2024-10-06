#include "words.hpp"
#include "iostream"

Words::Words()
{
    words = {"koala", "cat", "dog", "turtle", "elephant"};
    halfSize = 0;
    orginalSize = 0;
    position.x = 300;
    position.y = 300;
    saveTable = false;
}

std::vector<std::string> *Words::ViewWords()
{
    return &words;
}

int Words::GetWordSize(std::string word)
{
    return word.size();
}

void Words::DrawLines(int wordSize, char *arrayWord)
{
    arrayWord[wordSize] = '\0'; // Must finish array end sign, array end sign
    DrawText(arrayWord, position.x, position.y, 50, WHITE);
}

char *Words::GetChars(std::string word, int wordSize)
{
    char *wordArray = new char[wordSize];

    for (int i = 0; i < wordSize; i++)
    {
        wordArray[i] = word[i];
    }

    wordArray[wordSize] = '\0';

    return wordArray;
}

char *Words::BlackWords(int wordSize)
{
    char *blackWordArray = new char[wordSize];

    for (int i = 0; i < wordSize; i++)
    {
        blackWordArray[i] = '_';
    }

    blackWordArray[wordSize] = '\0'; // Must end create table empty sign

    return blackWordArray;
}

int Words::EndRare(int tableSize)
{
    int rare = 0;

    if (!saveTable)
    {
        halfSize = (tableSize + 1) / 2;
        orginalSize = tableSize - 1;
        saveTable = true;
    }

    if (tableSize == 0)
        rare = 5;
    if ((tableSize < halfSize) && (tableSize != 0))
        rare = 4;
    if (tableSize == halfSize)
        rare = 3;
    if ((tableSize > halfSize) && (tableSize != 0))
        rare = 2;

    std::cout << "tableSize: " << tableSize << std::endl;
    std::cout << "halfSize: " << halfSize << std::endl;

    return rare;
}