#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : rawBits(other.rawBits) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) // don’t do anything if i'm assigning to myself
    rawBits = other.rawBits;
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return rawBits;
}

void Fixed::setRawBits(int raw) {
  std::cout << "setRawBits member function called" << std::endl;
  rawBits = raw;
}
