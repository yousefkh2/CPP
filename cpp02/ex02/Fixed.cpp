#include "Fixed.hpp"
#include <cmath>

// const. / destr.
Fixed::Fixed() : _raw(0) {}

Fixed::Fixed(const int value) : _raw(value << _fractBits) {}

Fixed::Fixed(const float value)
    : _raw(static_cast<int>(roundf(value * (1 << _fractBits)))) {}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  _raw = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhs) {
  if (this != &rhs)
    this->_raw = rhs._raw;
  return *this;
}

Fixed::~Fixed() {}

// comparison operators
bool Fixed::operator>(const Fixed &rhs) const { return _raw > rhs._raw; }
bool Fixed::operator<(const Fixed &rhs) const { return _raw < rhs._raw; }
bool Fixed::operator>=(const Fixed &rhs) const { return _raw >= rhs._raw; }
bool Fixed::operator<=(const Fixed &rhs) const { return _raw <= rhs._raw; }
bool Fixed::operator==(const Fixed &rhs) const { return _raw == rhs._raw; }
bool Fixed::operator!=(const Fixed &rhs) const { return _raw != rhs._raw; }

// arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const {
  Fixed result;
  result._raw = this->_raw + rhs._raw;
  return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
  Fixed result;
  result._raw = this->_raw - rhs._raw;
  return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
  Fixed result;
  long tmp = static_cast<long>(this->_raw) * rhs._raw;
  result._raw = static_cast<int>(tmp >> _fractBits);
  return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
  Fixed result;
  long tmp = (static_cast<long>(this->_raw) << _fractBits) / rhs._raw;
  result._raw = static_cast<int>(tmp);
  return result;
}

// increment / decrement
Fixed &Fixed::operator++() {
  ++_raw;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  ++_raw;
  return tmp;
}

Fixed &Fixed::operator--() {
  --_raw;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  --_raw;
  return tmp;
}

// raw access and conversion
int Fixed::getRawBits(void) const { return _raw; }

void Fixed::setRawBits(int const raw) { _raw = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(_raw) / (1 << _fractBits);
}

int Fixed::toInt(void) const { return _raw >> _fractBits; }

// min and max
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b) ? a : b;
}

// stream insertion
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}