#include "ScalarConverter.hpp"
#include <cstdlib>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Please provide a literal for conversion" << std::endl;
    return EXIT_FAILURE;
  }

  if (argc > 2) {
    std::cerr << "Too many arguments" << std::endl;
    return EXIT_FAILURE;
  }

  try {
    ScalarConverter::convert(argv[1]);
  } catch (std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
