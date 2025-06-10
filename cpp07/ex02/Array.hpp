#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
private:
  T *_elements;
  unsigned int _size;

public:
  Array();
  Array(unsigned int n); // parameterized constr. -> creates an array of
                         // elements
  Array(const Array<T> &other);
  Array<T> &operator=(const Array<T> &other);
  ~Array();

  // subscript operator for element access
  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;

  // size member function
  unsigned int size() const;

  // exception class for out of bounds
  class OutOfBoundsException : public std::runtime_error {
  public:
    OutOfBoundsException();
  };
};

#include "Array.tpp"