#include "Fixed.hpp"
#include <iostream>

// int main(void) {
//   Fixed a;
//   Fixed const b(10);
//   Fixed const c(42.42f);
//   Fixed const d(b);
//   a = Fixed(1234.4321f);

//   std::cout << "a is " << a << std::endl;
//   std::cout << "b is " << b << std::endl;
//   std::cout << "c is " << c << std::endl;
//   std::cout << "d is " << d << std::endl;

//   std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//   std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//   std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//   std::cout << "d is " << d.toInt() << " as integer" << std::endl;

//   return 0;
// }

// main.cpp

int main() {
    std::cout << std::boolalpha;
    std::cout << "--- Constructors & Assignment ---\n";
    Fixed a;                        
    Fixed const b(10);              
    Fixed const c(42.42f);          
    Fixed const d(b);               
    Fixed e;                         
    e = Fixed(1234.4321f);          

    std::cout << "\n--- << operator (toFloat) ---\n";
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "c: " << c << "\n";
    std::cout << "d: " << d << "\n";
    std::cout << "e: " << e << "\n";

    std::cout << "\n--- toInt() conversion ---\n";
    std::cout << "a.toInt(): " << a.toInt() << "\n";
    std::cout << "b.toInt(): " << b.toInt() << "\n";
    std::cout << "c.toInt(): " << c.toInt() << "\n";
    std::cout << "d.toInt(): " << d.toInt() << "\n";
    std::cout << "e.toInt(): " << e.toInt() << "\n";

    std::cout << "\n--- toFloat() conversion (direct call) ---\n";
    std::cout << "a.toFloat(): " << a.toFloat() << "\n";
    std::cout << "b.toFloat(): " << b.toFloat() << "\n";
    std::cout << "c.toFloat(): " << c.toFloat() << "\n";
    std::cout << "d.toFloat(): " << d.toFloat() << "\n";
    std::cout << "e.toFloat(): " << e.toFloat() << "\n";

    return 0;
}
