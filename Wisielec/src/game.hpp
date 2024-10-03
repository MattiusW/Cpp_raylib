#include <raylib.h>
#include <vector>
#include <string>
#include <cstring>

class Game
{
public:
    Game();
    char HandleInput();
    char *CompareWords(char *guestWord, char *blackTable, char guestSign, int wordSize);
    void Win(char *guestTable, char *blackTable);
    void Lose(int life);
    bool Chance(char *guestWord, char guestSign, int wordSize);
    std::string DrawWord(std::vector<std::string> words);

private:
    std::vector<std::string> words;
    int drawNumber;
    bool chance;
};
