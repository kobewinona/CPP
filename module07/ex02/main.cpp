#include "Array.hpp"
#include <cstdlib>
#include <iostream>

#define RESET "\033[0m"
#define GRAY "\033[90m"
#define MAX_VAL 5
// #define MAX_VAL 750

int main(int, char **)
{
	// Test 1: Integer array
	std::cout << GRAY << "\n-- test 1 (integer array) --" << RESET << std::endl;
	Array<int> intArray(MAX_VAL);

	std::cout << "Before modification: ";
	for (size_t i = 0; i < MAX_VAL; ++i)
	{
		intArray[i] = i + 1;
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "After modification (increment each value): ";
	for (size_t i = 0; i < MAX_VAL; ++i)
	{
		intArray[i] += 1;
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	// Test 2: String array
	std::cout << GRAY << "\n-- test 2 (string array) --" << RESET << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "apple";
	strArray[1] = "banana";
	strArray[2] = "cherry";

	std::cout << "Before modification: ";
	for (size_t i = 0; i < 3; ++i)
		std::cout << strArray[i] << " ";
	std::cout << std::endl;

	std::cout << "After modification (append '!'): ";
	for (size_t i = 0; i < 3; ++i)
	{
		strArray[i] += "!";
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	// Test 3: Empty array (should not crash)
	std::cout << GRAY << "\n-- test 3 (empty array) --" << RESET << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;

	try
	{
		std::cout << "Attempting to access index 0 of empty array..." << std::endl;
		emptyArray[0] = 42; // This should throw an exception
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// Test 4: Copy constructor
	std::cout << GRAY << "\n-- test 4 (copy constructor) --" << RESET
			  << std::endl;
	Array<int> copiedArray = intArray;
	std::cout << "Original array: ";
	for (size_t i = 0; i < MAX_VAL; ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	std::cout << "Copied array: ";
	for (size_t i = 0; i < MAX_VAL; ++i)
		std::cout << copiedArray[i] << " ";
	std::cout << std::endl;

	std::cout << "Modifying copied array..." << std::endl;
	copiedArray[0] = 100;

	std::cout << "Original array after modification to copy: ";
	for (size_t i = 0; i < MAX_VAL; ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	std::cout << "Copied array after modification: ";
	for (size_t i = 0; i < MAX_VAL; ++i)
		std::cout << copiedArray[i] << " ";
	std::cout << std::endl;

	// Test 5: Assignment operator
	std::cout << GRAY << "\n-- test 5 (assignment operator) --" << RESET
			  << std::endl;

	std::cout << "Original array before assignment: ";
	for (size_t i = 0; i < MAX_VAL; ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	Array<int> assignedArray;
	assignedArray = intArray;

	std::cout << "Assigned array after assignment: ";
	for (size_t i = 0; i < MAX_VAL; ++i)
		std::cout << assignedArray[i] << " ";
	std::cout << std::endl;

	std::cout << "Modifying the assigned array..." << std::endl;
	assignedArray[0] = 100;

	std::cout << "Original array after modifying assigned array: ";
	for (size_t i = 0; i < MAX_VAL; ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	std::cout << "Assigned array after modification: ";
	for (size_t i = 0; i < MAX_VAL; ++i)
		std::cout << assignedArray[i] << " ";
	std::cout << "\n"
			  << std::endl;

	return EXIT_SUCCESS;
}

// #include <iostream>
// #include "Array.hpp"
// #include <cstdlib>

// #define MAX_VAL 750
// int main(int, char **)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int *mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	// SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete[] mirror; //
// 	return 0;
// }
