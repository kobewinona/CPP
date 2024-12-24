#include "BitcoinExchange.hpp"

// @defgroup constructors
BitcoinExchange::BitcoinExchange(const std::string &dataFileName)
{
	_dataFile.open(dataFileName.c_str());

	if (!_dataFile.is_open())
		throw std::runtime_error("Error: Unable to open file: " + dataFileName);

	_getExchangeRates();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_exchangeRates = other._exchangeRates;
	return *this;
}

// @def destructor
BitcoinExchange::~BitcoinExchange()
{
	if (_dataFile.is_open())
		_dataFile.close();
}

// @defgroup helper functions
std::ifstream *openFile(const std::string &fileName)
{
	std::ifstream *file = new std::ifstream(fileName.c_str());

	if (!file->is_open())
	{
		delete file;
		throw std::runtime_error("Error: Unable to open file: " + fileName);
	}

	return file;
}

void printError(const std::string &errorMessage,
				const std::string &fileName = "", int lineNumber = -1)
{
	std::cerr << RED << "Error: " << errorMessage;

	if (!fileName.empty())
	{
		std::cerr << " (file: " << fileName;
		if (lineNumber != -1)
			std::cerr << ", line: " << lineNumber;
		std::cerr << ")";
	}
	else if (lineNumber != -1)
		std::cerr << " (line: " << lineNumber << ")";

	std::cerr << RESET << std::endl;
}

// @defgroup member functions
void BitcoinExchange::_getExchangeRates()
{
	try
	{
		std::string line;
		if (!std::getline(_dataFile, line) || line.empty())
			throw std::runtime_error("Error: File is empty or unreadable.");

		int lineNumber = 2;
		while (std::getline(_dataFile, line))
		{
			std::istringstream ss(line);
			std::string date;
			float rate;

			if (std::getline(ss, date, ',') && ss >> rate)
				_exchangeRates[date] = rate;
			else
				printError("Invalid format in file at line", "", lineNumber);
			++lineNumber;
		}

		if (_exchangeRates.empty())
			throw std::runtime_error("Error: No valid data found in file.");
	}
	catch (const std::exception &e)
	{
		printError(e.what());
	}
}

void BitcoinExchange::printExchangeRates()
{
	// Print title
	std::cout << BOLD << "Exchange Rates: " << RESET << "\n";

	// Print column headers
	std::cout << std::left << std::setw(10) << "Index" << std::setw(15) << "Date"
			  << std::setw(15) << "Rate"
			  << "\n";

	// Print a line under the headers
	std::cout << std::setfill('-') << std::setw(40) << "-" << std::setfill(' ')
			  << "\n";

	// Print each row in the container
	int index = 0;
	for (std::map<std::string, float>::const_iterator it = _exchangeRates.begin();
		 it != _exchangeRates.end(); ++it)
	{
		std::cout << std::left << std::setw(10) << index << std::setw(15)
				  << it->first << std::setw(15) << it->second << "\n";
		++index;
	}

	std::cout << std::endl;
}

void BitcoinExchange::processInputFile(const std::string &inputFileName)
{
	try
	{
		std::ifstream inputFile(inputFileName.c_str());
		if (!inputFile.is_open())
			throw std::runtime_error("Error: Unable to open file: " + inputFileName);

		std::string line;
		if (!std::getline(inputFile, line) || line.empty())
			throw std::runtime_error("Error: File is empty or unreadable: " + inputFileName);

		std::cout << BOLD << "Converted Amounts:" << RESET << "\n";
		std::cout << std::left << std::setw(15) << "Date" << std::setw(15)
				  << "Value" << std::setw(15) << "ExchangeRate" << std::setw(15)
				  << "Result" << std::setw(35) << "" << "\n";
		std::cout << std::setfill('-') << std::setw(95) << "-" << std::setfill(' ') << "\n";

		int lineNumber = 2;
		while (std::getline(inputFile, line))
		{
			std::istringstream ss(line);
			std::string date;
			float value;

			// Parse the input line
			if (!(std::getline(ss, date, '|') && ss >> value))
			{
				printError(INVALID_FORMAT_ERR_MSG, inputFileName, lineNumber++);
				continue;
			}

			// Handle a number bigger than max value
			if (value > MAX_INPUT_VALUE)
			{
				printError(NUMBER_TOO_LARGE_ERR_MSG, inputFileName, lineNumber++);
				continue;
			}

			// Trim whitespace from date and value
			date.erase(date.find_last_not_of(WHITESPACE) + 1);
			date.erase(0, date.find_first_not_of(WHITESPACE));

			// Handle a number smaller than 0
			if (value <= 0)
			{
				printError(NUMBER_NOT_POSITIVE_ERR_MSG, inputFileName, lineNumber);
				++lineNumber;
				continue;
			}

			std::string closestDate;
			std::string warning;
			float rate;
			std::map<std::string, float>::const_iterator it =
				_exchangeRates.lower_bound(date);

			if (it == _exchangeRates.begin() && it->first != date)
			{
				printError(NO_RATE_FOR_GIVEN_DATE_ERR_MSG, inputFileName, lineNumber);
				++lineNumber;
				continue;
			}

			if (it == _exchangeRates.end() || it->first != date)
				--it;

			closestDate = it->first;
			rate = it->second;

			// Update the warning message if the date doesn't match
			if (closestDate != date)
				warning = std::string(YELLOW) + "Warning: using rate from " + closestDate + std::string(RESET);

			float result = value * rate;
			std::cout << std::fixed << std::setprecision(2);
			std::cout << std::left << std::setw(15) << date << std::setw(15) << value
					  << std::setw(15) << rate << std::setw(15) << result << warning << std::endl;

			++lineNumber;
		}

		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		printError(e.what());
	}
}
