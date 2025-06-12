#include <iostream>
#include <string>
#include "iter.hpp"

namespace Color {
    constexpr const char* RESET  = "\033[0m";
    constexpr const char* GREEN  = "\033[32m";
    constexpr const char* CYAN   = "\033[36m";
}

// Test functions for different types
void printInt(int& n) {
    std::cout << n << " ";
}

void printIntConst(const int& n) {
    std::cout << n << " ";
}

void doubleValue(int& n) {
    n *= 2;
}

void printString(const std::string& s) {
    std::cout << s << " ";
}

void printChar(const char& c) {
    std::cout << c;
}

// Function template that can work with iter
template<typename T>
void printGeneric(const T& value) {
    std::cout << value << " ";
}

template<typename T>
void increment(T& value) {
    ++value;
}

int main() {
    std::cout << Color::GREEN << "=== Testing iter function template ===" << Color::RESET << std::endl;

    // Test 1: Non-const int array with modifying function
    std::cout << Color::CYAN << "\nTest 1: Non-const int array with doubleValue function" << Color::RESET << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Before: ";
    iter(intArray, intSize, printInt);
    std::cout << std::endl;

    iter(intArray, intSize, doubleValue);

    std::cout << "After doubling: ";
    iter(intArray, intSize, printInt);
    std::cout << std::endl;

    // Test 2: Const int array with const function
    std::cout << Color::CYAN << "\nTest 2: Const int array with const function" << Color::RESET << std::endl;
    const int constIntArray[] = {10, 20, 30, 40, 50};
    size_t constIntSize = sizeof(constIntArray) / sizeof(constIntArray[0]);

    std::cout << "Const array: ";
    iter(constIntArray, constIntSize, printIntConst);
    std::cout << std::endl;

    // Test 3: String array
    std::cout << Color::CYAN << "\nTest 3: String array" << Color::RESET << std::endl;
    std::string stringArray[] = {"Hello", "World", "From", "Iter"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Strings: ";
    iter(stringArray, stringSize, printString);
    std::cout << std::endl;

    // Test 4: Char array
    std::cout << Color::CYAN << "\nTest 4: Char array" << Color::RESET << std::endl;
    char charArray[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    size_t charSize = 5;

    std::cout << "Chars: ";
    iter(charArray, charSize, printChar);
    std::cout << std::endl;

    // Test 5: Function template as third parameter
    std::cout << Color::CYAN << "\nTest 5: Using function template as third parameter" << Color::RESET << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Doubles with generic function: ";
    iter(doubleArray, doubleSize, printGeneric<double>);
    std::cout << std::endl;

    // Test 6: Non-const array with increment function template
    std::cout << Color::CYAN << "\nTest 6: Increment function template" << Color::RESET << std::endl;
    int incrementArray[] = {0, 1, 2, 3, 4};
    size_t incrementSize = sizeof(incrementArray) / sizeof(incrementArray[0]);

    std::cout << "Before increment: ";
    iter(incrementArray, incrementSize, printGeneric<int>);
    std::cout << std::endl;

    iter(incrementArray, incrementSize, increment<int>);

    std::cout << "After increment: ";
    iter(incrementArray, incrementSize, printGeneric<int>);
    std::cout << std::endl;

    // Test 7: Lambda function (C++11 feature)
    std::cout << Color::CYAN << "\nTest 7: Using lambda function" << Color::RESET << std::endl;
    int lambdaArray[] = {1, 2, 3, 4, 5};
    size_t lambdaSize = sizeof(lambdaArray) / sizeof(lambdaArray[0]);

    std::cout << "Squares: ";
    iter(lambdaArray, lambdaSize, [](const int& n) {
        std::cout << n * n << " ";
    });
    std::cout << std::endl;

    std::cout << Color::GREEN << "\n=== All iter tests completed ===" << Color::RESET << std::endl;
    return 0;
}
