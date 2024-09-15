#pragma once

#include <string>

template <typename T> class Array {
private:
  T *_elements;
  size_t _size;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &other);
  Array &operator=(const Array &other);
  ~Array();

  // @defgroup setters/getters
  size_t size() const;

  // @defgroup operator override
  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;
};

#include "Array.tpp"