#include <string>
#include <vector>
#include <raylib.h>

class Words
{
public:
    Words();
    std::vector<std::string> *ViewWords();
    int GetWordSize(std::string word);
    void DrawLines(int wordSize, char *arrayWord);
    char *GetChars(std::string word, int wordSize);
    char *BlackWords(int wordSize);

private:
    std::vector<std::string> words;
    Vector2 position;
};