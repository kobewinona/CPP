#include "Data.hpp"
#include "Serializer.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main() {
  Data data = {1, "0", "label"};

  uintptr_t raw = Serializer::serialize(&data);
  Data *ptr = Serializer::deserialize(raw);

  if (ptr == &data) {
    std::cout << std::left << "Serialization and deserialization successful."
              << std::endl;
    std::cout << std::setw(15) << "Data id: " << ptr->id << std::endl;
    std::cout << std::setw(15) << "Data value: " << ptr->value << std::endl;
    std::cout << std::setw(15) << "Data label: " << ptr->label << std::endl;
  } else
    std::cout << "Serialization and deserialization failed." << std::endl;

  return EXIT_SUCCESS;
}
