#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

void printError(const std::string &errorMessage) {
  std::cerr << RED << "Error: " << errorMessage << RESET << std::endl;
}

bool isPositiveInteger(const std::string &str) {
  for (size_t i = 0; i < str.size(); ++i) {
    if (!isdigit(str[i]))
      return false;
  }
  return !str.empty();
}

int main(int argc, char **argv) {
  if (argc <= 1) {
    printError("Provide a sequence of positive integers as arguments.");
    return EXIT_FAILURE;
  }

  std::vector<int> input;

  for (int i = 1; i < argc; ++i) {
    if (!isPositiveInteger(argv[i])) {
      printError("Invalid input. Only positive integers are allowed.");
      return EXIT_FAILURE;
    }
    input.push_back(std::atoi(argv[i]));
  }

  PmergeMe PmergeMe(input);
  PmergeMe.printContainer("Unsorted input: ", input);
  PmergeMe.execute();

  return EXIT_SUCCESS;
}