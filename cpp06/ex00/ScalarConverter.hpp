#pragma once
#include <string>

class ScalarConverter {
private:
  // Private constructor to prevent instantiation
  ScalarConverter() = default;
  ScalarConverter(const ScalarConverter &other) = default;
  ScalarConverter &operator=(const ScalarConverter &other) = default;
  ~ScalarConverter() = default;

public:
  static void convert(const std::string &literal);
};
