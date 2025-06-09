#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

static bool isPseudoFloat(const std::string &s) {
  return (s == "nanf" || s == "+inff" || s == "-inff");
}

static bool isPseudoDouble(const std::string &s) {
  return (s == "nan" || s == "+inf" || s == "-inf");
}

void ScalarConverter::convert(const std::string &literal) {
  // TODO: Implement the conversion logic here
  // This method should:
  // 1. Detect the type of the input literal
  if (literal.size() == 3 && literal.front() == '\'' &&
      literal.back() == '\'') {
    char c = literal[1]; // we already know it's a displayable char (from the
                         // subject)
    int asInt = static_cast<int>(c);
    float asFloat = static_cast<float>(c);
    double asDouble = static_cast<double>(c);

    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << asInt << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << asFloat << "f\n";
    std::cout << "double: " << asDouble << "\n";
    return;
  }

  // INT SECTION
  errno = 0;              // overflow alarm
  char *endptr = nullptr; // whatever's cannot be parsed, is thrown here
  long intVal = std::strtol(literal.c_str(), &endptr, 10);
  if (errno == 0 && endptr != literal.c_str() && *endptr == '\0') {
    // if it is a valid long, now check range for 32-bit int
    if (intVal < std::numeric_limits<int>::min() ||
        intVal > std::numeric_limits<int>::max()) {
      std::cout << "char: impossible\n";
      std::cout << "int: overflow\n";
      std::cout << "float: overflow\n";
      std::cout << "double: overflow\n";
      return;
    }

    int asInt = static_cast<int>(intVal);
    char asChar = static_cast<char>(asInt);
    float asFloat = static_cast<float>(asInt);
    double asDouble = static_cast<double>(asInt);

    if (std::isprint(asChar))
      std::cout << "char: '" << asChar << "'\n";
    else
      std::cout << "char: Non displayable\n";

    std::cout << "int: " << asInt << "\n";

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << asFloat << "f\n";
    std::cout << "double: " << asDouble << "\n";
    return;
  }

  // FLOAT SECTION
  if (isPseudoFloat(literal) ||
      (literal.back() == 'f' && literal.find('.') != std::string::npos)) {
    if (isPseudoFloat(literal)) {
      std::string base =
          literal.substr(0, literal.size() - 1); // remove the last letter
      std::cout << "char: impossible\n";
      std::cout << "int: impossible\n";
      std::cout << "float: " << base << "f\n";
      std::cout << "double: " << base << "\n";
      return;
    }
    // otheriwese parse as float (strtof)
    errno = 0;
    char *endptrF = nullptr;
    float fVal = std::strtof(literal.c_str(), &endptrF);
    // strtof will stop at the 'f' if it parsed successfully
    if (errno == 0 && endptrF != literal.c_str() && *endptrF == 'f' &&
        *(endptrF + 1) == '\0') {
      char asChar = static_cast<char>(fVal);
      int asInt = static_cast<int>(fVal);
      double asDouble = static_cast<double>(fVal);

      if (std::isnan(fVal) || std::isinf(fVal)) {
        // For NaN or inf, char/int are “impossible”
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
      } else {
        if (std::isprint(asChar))
          std::cout << "char: '" << asChar << "'\n";
        else
          std::cout << "char: Non displayable\n";
        std::cout << "int: " << asInt << "\n";
      }

      std::cout << std::fixed << std::setprecision(1);
      std::cout << "float: " << fVal << "f\n";
      std::cout << "double: " << asDouble << "\n";
      return;
    }
  }
  // DOUBLE SECTION
  if (isPseudoDouble(literal) || literal.find('.') != std::string::npos)
    {
        // Handle pseudo‐double:
        if (isPseudoDouble(literal))
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: "  << literal << "f\n";
            std::cout << "double: " << literal << "\n";
            return;
        }

        // Parse as double:
        errno = 0;
        char* endptrD = nullptr;
        double dVal = std::strtod(literal.c_str(), &endptrD);
        if (errno == 0 && endptrD != literal.c_str() && *endptrD == '\0')
        {
            char  asChar   = static_cast<char>(dVal);
            int   asInt    = static_cast<int>(dVal);
            float asFloat  = static_cast<float>(dVal);

            if (std::isnan(dVal) || std::isinf(dVal)) {
                std::cout << "char: impossible\n";
                std::cout << "int: impossible\n";
            }
            else {
                if (std::isprint(asChar))
                    std::cout << "char: '" << asChar << "'\n";
                else
                    std::cout << "char: Non displayable\n";
                std::cout << "int: " << asInt << "\n";
            }

            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: "  << asFloat  << "f\n";
            std::cout << "double: " << dVal     << "\n";
            return;
        }
    }

  // 2. Convert it to char, int, float, and double
  // 3. Handle special cases like pseudo-literals (-inff, +inff, nanf, -inf,
  // +inf, nan)
  // 4. Handle non-displayable characters for char conversion
  // 5. Print appropriate error messages for impossible conversions

  std::cout << "char: " << std::endl;
  std::cout << "int: " << std::endl;
  std::cout << "float: " << std::endl;
  std::cout << "double: " << std::endl;
}
