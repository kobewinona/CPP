#include "RPN.hpp"
#include <cstdlib>
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

void printError(const std::string &errorMessage) {
  std::cerr << RED << "Error: " << errorMessage << RESET << std::endl;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./RPN <expression>" << std::endl;
    return 1;
  }

  std::string expression = argv[1];
  long result;

  try {
    result = RPN::processExpression(expression);
    std::cout << "Result: " << result << std::endl;
  } catch (std::exception &e) {
    printError(e.what());
  }

  return EXIT_SUCCESS;
}