#include "Fixed.hpp"
#include <iostream>

// int main(void) {
//   Fixed a;
//   Fixed const b(Fixed(5.05f) * Fixed(2));

//   std::cout << a << std::endl;
//   std::cout << ++a << std::endl;
//   std::cout << a << std::endl;
//   std::cout << a++ << std::endl;
//   std::cout << a << std::endl;

//   std::cout << b << std::endl;
//   std::cout << Fixed::max(a, b) << std::endl;

//   return 0;
// }

// main.cpp

int main() {
  std::cout << std::boolalpha; // print true/false for bools

  Fixed a(2);
  Fixed b(5);

  std::cout << "a = "      << a << ", b = "      << b << "\n\n";

  // 1) Comparison operators
  std::cout << "Comparison:\n";
  std::cout << "  a >  b: " << (a >  b) << "\n";
  std::cout << "  a <  b: " << (a <  b) << "\n";
  std::cout << "  a >= b: " << (a >= b) << "\n";
  std::cout << "  a <= b: " << (a <= b) << "\n";
  std::cout << "  a == b: " << (a == b) << "\n";
  std::cout << "  a != b: " << (a != b) << "\n\n";

  // 2) Arithmetic operators
  std::cout << "Arithmetic:\n";
  std::cout << "  a + b = " << (a + b) << "\n";
  std::cout << "  a - b = " << (a - b) << "\n";
  std::cout << "  a * b = " << (a * b) << "\n";
  std::cout << "  b / a = " << (b / a) << "\n\n";

  // 3) Increment / decrement
  Fixed c(0);
  std::cout << "Increment/Decrement:\n";
  std::cout << "  c       = " << c       << "\n";
  std::cout << "  ++c     = " << ++c     << "\n";
  std::cout << "  c++     = " <<  c++    << "\n";
  std::cout << "  now c   = " <<   c     << "\n";
  std::cout << "  --c     = " << --c     << "\n";
  std::cout << "  c--     = " <<  c--    << "\n";
  std::cout << "  now c   = " <<   c     << "\n\n";

  // 4) Static min/max (non-const and const overloads)
  Fixed x(10), y(20);
  std::cout << "min(x,y)  = " << Fixed::min(x, y) << "\n";
  std::cout << "max(x,y)  = " << Fixed::max(x, y) << "\n\n";

  const Fixed cx(3), cy(7);
  std::cout << "min(cx,cy)= " << Fixed::min(cx, cy) << "\n";
  std::cout << "max(cx,cy)= " << Fixed::max(cx, cy) << "\n";

  return 0;
}
