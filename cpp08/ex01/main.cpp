
#include "Span.hpp"
#include <iostream>
#include <numeric>
#include <vector>

int main(void) {
  Span span(10000);
  std::vector<int> bigRange(10000);
  std::iota(bigRange.begin(), bigRange.end(), 0);
  span.addNumbers(bigRange.begin(), bigRange.end());
  std::cout << "Shortest span: " << span.shortestSpan() << "\n";
  std::cout << "Longest span: " << span.longestSpan() << "\n";
  try {
    span.addNumber(10001); // should throw
  } catch (std::exception &e) {
    std::cout << "Overflow correctly caught: " << e.what() << "\n";
  }
}

//TODO:
// 1. reorganize into cpp
// 2. make sure all is in OCF
// 3. add more test cases + color everything in
// 4. final checks and submit
