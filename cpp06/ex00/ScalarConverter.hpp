#pragma once
#include <string>

class ScalarConverter {
private:
  ScalarConverter() = default;
  ScalarConverter(const ScalarConverter &other) = default;
  ScalarConverter &operator=(const ScalarConverter &other) = default;
  ~ScalarConverter() = default;

public:
  static void convert(const std::string &literal);
};
