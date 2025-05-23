#pragma once

#include <iostream>

class Fixed {
private:
  int _raw;
  static const int _fractBits = 8;

public:
  Fixed();                            // default
  Fixed(int const value);             // int constructor
  Fixed(float const value);           // float constructor
  Fixed(const Fixed &other);          // ccopy
  Fixed &operator=(const Fixed &rhs); // assign
  ~Fixed();                           // destructor

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
