#pragma once
#include <iostream>

class Fixed {
private:
  int _raw;
  static const int _fractBits = 8;

public:
  Fixed();                            // default constructor
  Fixed(const Fixed &other);          // copy constructor
  Fixed &operator=(const Fixed &rhs); // copy assignment
  ~Fixed();                           // destructor

  int getRawBits(void) const;
  void setRawBits(int const raw);
};