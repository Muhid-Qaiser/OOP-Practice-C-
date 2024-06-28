#include <iostream>
#include <string>

void tokenize(const std::string &sentence)
{
    std::string token;
    std::string delimiter = " ";

    for (char ch : sentence)
    {
        if (ch == delimiter[0])
        {
            std::cout << token << std::endl;
            token.clear();
        }
        else
        {
            token += ch;
        }
    }

    std::cout << token << std::endl;
}

int main()
{
    std::string sentence = "Hello, world! How are you?";
    tokenize(sentence);

    return 0;
}
