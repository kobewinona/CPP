#include "iter.hpp"
#include <cstdlib>
#include <iostream>

#define RESET "\033[0m"
#define GRAY "\033[90m"

void increment(int &n) { n += 1; }

void toUpperCase(std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	}
}

int print(std::string &str)
{
	std::cout << str << std::endl;
	return str.length();
}

int main()
{
	// Test 1: Integer array
	std::cout << GRAY << "\n-- test 1 (integer array) --" << RESET << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Before iter (increment): ";
	for (size_t i = 0; i < intArrayLen; ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	iter(intArray, intArrayLen, increment);

	std::cout << "After iter (increment): ";
	for (size_t i = 0; i < intArrayLen; ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	// Test 2: String array
	std::cout << GRAY << "\n-- test 2 (string array) --" << RESET << std::endl;
	std::string strArray[] = {"apple", "banana", "cherry"};
	size_t strArrayLen = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Before iter (toUpperCase): ";
	for (size_t i = 0; i < strArrayLen; ++i)
		std::cout << strArray[i] << " ";
	std::cout << std::endl;

	iter(strArray, strArrayLen, toUpperCase);

	std::cout << "After iter (toUpperCase): ";
	for (size_t i = 0; i < strArrayLen; ++i)
		std::cout << strArray[i] << " ";
	std::cout << std::endl;

	// Test 3: Empty array (should not crash)
	std::cout << GRAY << "\n-- test 3 (empty array) --" << RESET << std::endl;
	int emptyArray[] = {};
	size_t emptyArrayLen = sizeof(emptyArray) / sizeof(emptyArray[0]);

	std::cout << "Empty array size: " << emptyArrayLen << std::endl;
	iter(emptyArray, emptyArrayLen, increment);

	// Test 4: String array with print non void function
	std::cout << GRAY << "\n-- test 4 (with print non void function) --" << RESET << std::endl;

	iter(strArray, strArrayLen, print);

	return EXIT_SUCCESS;
}
