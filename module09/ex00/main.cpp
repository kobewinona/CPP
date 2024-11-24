#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  (void)argv;
  if (argc < 2) {
    std::cout << "Please provide a file with values to convert" << std::endl;
    return EXIT_SUCCESS;
  }

  BitcoinExchange btc("data.csv");
  btc.processInputFile(std::string(argv[1]));

  return EXIT_SUCCESS;
}