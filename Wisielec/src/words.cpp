#include "words.hpp"

Words::Words()
{
    words = {"cat", "dog", "turtle", "koala"};
}

std::vector<std::string> Words::ViewWords()
{
    return words;
}
