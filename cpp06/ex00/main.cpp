// main.cpp
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main()
{
    const std::string tests[] = {
        "'a'",       // simple char
        "'Z'",       // another char
        "0",         // zero as int
        "42",        // positive int
        "-42",       // negative int
        "2147483648",// int overflow (one past 32-bit max)
        "4.2f",      // float literal
        "-0.0f",     // negative zero float
        "nanf",      // float pseudo-literal
        "+inff",     // float pseudo-literal
        "4.2",       // double literal
        "-0.0",      // negative zero double
        "nan",       // double pseudo-literal
        "+inf",      // double pseudo-literal
        "123abc",    // invalid
        "abc",       // invalid
        ""           // empty string
    };

    for (const auto& lit : tests)
    {
        std::cout << "=== Input: \"" << lit << "\" ===\n";
        ScalarConverter::convert(lit);
        std::cout << "==========================\n\n";
    }

    return 0;
}
