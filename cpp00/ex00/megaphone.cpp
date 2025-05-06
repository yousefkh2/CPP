#include <iostream>
#include <string>
#include <cctype>

std::string loudify(const std::string& input)
{
    std::string result;

    for (char ch : input)
    {
        result += static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
    }
    return result;
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    std::string output;
    for (int i = 1; i < argc; ++i)
    {
        output += loudify(argv[i]);
    }
    std::cout << output << std::endl;
	return 0;
}

