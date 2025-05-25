#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _raw(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _raw(value << _fractBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _raw(roundf(value * (1 << _fractBits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  _raw = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
    this->_raw = rhs.getRawBits();
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _raw;
}

void Fixed::setRawBits(int const raw) { _raw = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(_raw) / (1 << _fractBits);
}

int Fixed::toInt(void) const { return _raw >> _fractBits; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}