#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

// @defgroup typography
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

// @defgroup constants
#define MAX_INPUT_VALUE 1000
#define WHITESPACE " \t\r\n"

// @defgroup error messages
#define NUMBER_TOO_LARGE_ERR_MSG "Number is too large"
#define INVALID_FORMAT_ERR_MSG "Invalid number format"
#define NUMBER_NOT_POSITIVE_ERR_MSG "Not a positive number"
#define NO_RATE_FOR_GIVEN_DATE_ERR_MSG "No rate for date"

class BitcoinExchange {
private:
  std::map<std::string, float> _exchangeRates;

  void _getExchangeRates(const std::string &dataFileName);

public:
  BitcoinExchange(const std::string &dataFileName);
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  void printExchangeRates();
  void processInputFile(const std::string &inputFileName);
};
