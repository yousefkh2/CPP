#pragma once

// fully defined in the header. That's unique to templates.
template <typename T> void swap(T &a, T &b) {
  T tmp = a; // used copy-constructor instead of default const. bec. not all
             // types in C++ can be default constructed.
  a = b;
  b = tmp;
}

template <typename T> T const &min(T const &a, T const &b) {
  return (a < b) ? a : b;
}

template <typename T> T const &max(T const &a, T const &b) {
  return (a > b) ? a : b;
}
