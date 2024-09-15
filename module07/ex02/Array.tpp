#include "Array.hpp"
#include <iostream>

// @defgroup constructors
template <typename T> Array<T>::Array() : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n) {
  for (size_t i = 0; i < n; ++i)
    _elements[i] = T();
}

// Copy constructor
template <typename T> Array<T>::Array(const Array<T> &other) {
  _elements = new T[other._size];
  _size = other._size;

  for (size_t i = 0; i < _size; ++i)
    _elements[i] = other._elements[i];
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
  if (this != &other) {
    T *new_elements = new T[other._size];
    for (size_t i = 0; i < other._size; ++i)
      new_elements[i] = other._elements[i];

    delete[] _elements;
    _elements = new_elements;
    _size = other._size;
  }
  return *this;
}

// @def destructor
template <typename T> Array<T>::~Array() { delete[] _elements; }

// @defgroup setters/getters
template <typename T> size_t Array<T>::size() const { return _size; }

// @defgroup operator override
// - allows modification of array elements
template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= _size)
    throw std::out_of_range("Index out of bounds");

  return _elements[index];
}

// - read-only access for const objects
template <typename T> const T &Array<T>::operator[](unsigned int index) const {
  if (index >= _size)
    throw std::out_of_range("Index out of bounds");

  return _elements[index];
}