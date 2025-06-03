#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <climits>


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    // TODO: Implement the conversion logic here
    // This method should:
    // 1. Detect the type of the input literal
    // 2. Convert it to char, int, float, and double
    // 3. Handle special cases like pseudo-literals (-inff, +inff, nanf, -inf, +inf, nan)
    // 4. Handle non-displayable characters for char conversion
    // 5. Print appropriate error messages for impossible conversions
    
    std::cout << "char: " << std::endl;
    std::cout << "int: " << std::endl;
    std::cout << "float: " << std::endl;
    std::cout << "double: " << std::endl;
}
