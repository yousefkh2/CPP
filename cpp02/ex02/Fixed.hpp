#pragma once

#include <iostream>

class Fixed {
private:
  int _raw;
  static const int _fractBits = 8;

public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &rhs);
  ~Fixed();

  // comparison operators
  bool operator>(const Fixed &rhs) const;
  bool operator<(const Fixed &rhs) const;
  bool operator>=(const Fixed &rhs) const;
  bool operator<=(const Fixed &rhs) const;
  bool operator==(const Fixed &rhs) const;
  bool operator!=(const Fixed &rhs) const;

  // arithmetic operators
  Fixed operator+(const Fixed &rhs) const;
  Fixed operator-(const Fixed &rhs) const;
  Fixed operator*(const Fixed &rhs) const;
  Fixed operator/(const Fixed &rhs) const;

  // increment / decrement
  Fixed &operator++();  
  Fixed operator++(int);
  Fixed &operator--();  
  Fixed operator--(int);

  // raw access
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  // min / max
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);