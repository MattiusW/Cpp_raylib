#include "words.hpp"
#include "iostream"

Words::Words()
{
    words = {"koala", "cat", "dog", "turtle"};
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
        std::cout << word[i] << std::endl;
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
