

// #include <iostream>
// #include <cctype>


// int main(int argc, char **argv)
// {
// 	if (argc == 1)
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
// 	else
// 	{
// 		for (int i = 1; i < argc; i++)
// 		{
// 			for (int j = 0; argv[i][j]; j++)
// 			{
// 				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
// 			}
			
// 		}
// 		std::cout << std::endl;
// 	}
// 	return 0;
// }



// #include <iostream>
// #include <string>
// #include <cctype>

// int main(int argc, char* argv[]) {
//     const std::string fallback = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

//     if (argc == 1) {
//         std::cout << fallback << '\n';
//         return 0;
//     }

//     for (int i = 1; i < argc; ++i) {
//         std::string s(argv[i]);
//         for (char& c : s) {
//             c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
//         }
//         std::cout << s;
//     }

//     std::cout << '\n';
//     return 0;
// }



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
}

