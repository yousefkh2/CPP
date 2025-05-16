#include <fstream>
#include <iostream>
#include <string>

static std::string replace_all(const std::string &input, const std::string &s1,
                               const std::string &s2) {
  if (s1.empty())
    return input;

  std::string result;
  std::size_t pos = 0;
  std::size_t found = 0;

  while (true) {
    found = input.find(s1, pos);
    if (found == std::string::npos)
      break;
    result.append(input, pos, found - pos);
    result.append(s2);
    pos = found + s1.length();
  }
  result.append(input, pos, input.length() - pos);
  return result;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
    return 1;
  }

  const std::string filename = argv[1];
  const std::string s1 = argv[2];
  const std::string s2 = argv[3];

  if (s1.empty()) {
    std::cerr << "Error: string to replace (s1) must not be empty\n";
    return 1;
  }

  std::ifstream input(filename);
  if (!input) {
    std::cerr << "Error: could not open file '" << filename << "'\n";
    return 1;
  }

  const std::string out_name = filename + ".replace";
  std::ofstream output(out_name);
  if (!output) {
    std::cerr << "Error: could not create file '" << out_name << "'\n";
    return 1;
  }

  std::string line;
  bool first = true;
  while (std::getline(input, line)) {
    std::string replaced = replace_all(line, s1, s2);
    if (!first) {
      output << '\n';
    }
    first = false;
    output << replaced;
    if (!output) {
      std::cerr << "Error: writing to file '" << out_name << "'\n";
      return 1;
    }
  }

  return 0;
}
