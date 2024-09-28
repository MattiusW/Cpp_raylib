#include <raylib.h>
#include <vector>
#include <string>

class Game
{
public:
    Game();
    std::string DrawWord(std::vector<std::string>);

private:
    std::vector<std::string> words;
    int drawNumber;
};
