#include "words.hpp"

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
