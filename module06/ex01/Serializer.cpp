#include "Serializer.hpp"

// @defgroup constructors
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other) { (*this) = other; }
Serializer &Serializer::operator=(const Serializer &other) {
  (void)other;
  return *this;
}

// @def destructor
Serializer::~Serializer() {}

// @def member functions
uintptr_t Serializer::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}