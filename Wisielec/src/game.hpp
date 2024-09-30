#include <raylib.h>
#include <vector>
#include <string>

class Game
{
public:
    Game();
    char HandleInput();
    char *CompareWords(char *guestWord, char *blackTable, char guestSign, int wordSize);
    std::string DrawWord(std::vector<std::string>);

private:
    std::vector<std::string> words;
    int drawNumber;
};
