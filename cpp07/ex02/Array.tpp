#pragma once

// default constr.
template <typename T> 
Array<T>::Array() : _elements(nullptr), _size(0) {
  std::cout << "Array default constructor called" << std::endl;
}

// parameterized constr.
template <typename T>
Array<T>::Array(unsigned int n) : _elements(nullptr), _size(n) {
  std::cout << "Array parameterized constructor called with size " << n
            << std::endl;
  if (n > 0) {
    _elements = new T[n](); // () ensures default initialiation
  }
}

// copy constructor
template <typename T>
Array<T>::Array(const Array<T> &other)
    : _elements(nullptr), _size(other._size) {
  std::cout << "Array copy constructor called" << std::endl;
  if (_size > 0) {
    _elements = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
      _elements[i] = other._elements[i];
    }
  }
}

// assignment operator
template <typename T> 
Array<T> &Array<T>::operator=(const Array<T> &other) {
  std::cout << "Array assignment operator called" << std::endl;
  if (this != &other) {
    delete[] _elements;
    // Copy size and allocate new memory
    _size = other._size;
    if (_size > 0) {
      _elements = new T[_size];
      for (unsigned int i = 0; i < _size; i++) {
        _elements[i] = other._elements[i];
      }
    } else {
      _elements = NULL;
    }
  }
  return *this;
}

// destuctor
template <typename T> Array<T>::~Array() {
  std::cout << "Array destructor called" << std::endl;
  delete[] _elements;
}
