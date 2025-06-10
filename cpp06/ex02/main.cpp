#include "identify.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  std::cout << "### Normal randomized tests ###\n";
  for (int i = 0; i < 5; ++i) {
    Base *obj = generate();
    std::cout << "Pointer: ";
    identify(obj);
    std::cout << "Reference: ";
    identify(*obj);
    delete obj;
    std::cout << std::endl;
  }

  std::cout << "### nullptr tests ###\n";
  Base *nullObj = nullptr;

  std::cout << "Pointer: ";
  identify(nullObj);

  std::cout << "Reference: ";
  if (nullObj != nullptr)
    identify(*nullObj); 
  else
    std::cout << "Cannot identify null reference\n";

  return 0;
}
