#include <string>
#include <vector>

class Words
{
public:
    Words();
    std::vector<std::string> ViewWords();

private:
    std::vector<std::string> words;
};