#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static std::string replace_all(
    std::string const& input,
    std::string const& from,
    std::string const& to)
{
    std::string result;
    std::size_t pos = 0;
    std::size_t found;
    
    // Iterate over each occurrence of 'from'
    while ((found = input.find(from, pos)) != std::string::npos) {
        // Copy up to the match
        result.append(input, pos, found - pos);
        // Append replacement
        result.append(to);
        // Advance past the match
        pos = found + from.length();
    }
    // Append remainder
    result.append(input, pos, input.length() - pos);
    return result;
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: string to replace (s1) must not be empty\n";
        return 1;
    }

    std::ifstream input(filename);
    if (!input) {
        std::cerr << "Error: could not open file '" << filename << "'\n";
        return 1;
    }

    // Read entire file into a string
    std::ostringstream buffer;
    buffer << input.rdbuf();
    std::string content = buffer.str();

    // Perform replacement
    std::string replaced = replace_all(content, s1, s2);

    // Write to <filename>.replace
    std::string out_name = filename + ".replace";
    std::ofstream output(out_name);
    if (!output) {
        std::cerr << "Error: could not create file '" << out_name << "'\n";
        return 1;
    }

    output << replaced;
    if (!output) {
        std::cerr << "Error: writing to file '" << out_name << "'\n";
        return 1;
    }

    return 0;
}
