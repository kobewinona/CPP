
#include "easyfind.hpp"
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>
#include <stack>

#define RESET "\033[0m"
#define GRAY "\033[90m"
#define MAX_VAL 5
// #define MAX_VAL 750

int main()
{
	// Test 1: container: Vector
	std::cout << GRAY << "\n-- test 1 (container: vector) --";
	std::cout << RESET << std::endl;

	std::vector<int> myVector;
	for (unsigned int i = 0; i < MAX_VAL; ++i)
		myVector.push_back(i + 1);

	try
	{
		std::cout << "Attempting to find element: 3..." << std::endl;
		std::vector<int>::iterator result = easyfind(myVector, 3);
		std::cout << "Found: " << *result << std::endl;
	}
	catch (const NotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Attempting to find element: MAX_VAL + 1..." << std::endl;
		std::vector<int>::iterator result = easyfind(myVector, MAX_VAL + 1);
		std::cout << "Found: " << *result << std::endl;
	}
	catch (const NotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test 2: container: List
	std::cout << GRAY << "\n-- test 2 (container: list) --" << RESET << std::endl;
	std::list<int> myList;
	for (unsigned int i = 0; i < MAX_VAL; ++i)
		myList.push_back(i + 1);

	try
	{
		std::cout << "Attempting to find element: 3..." << std::endl;
		std::list<int>::iterator result = easyfind(myList, 3);
		std::cout << "Found: " << *result << std::endl;
	}
	catch (const NotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Attempting to find element: MAX_VAL + 1..." << std::endl;
		std::list<int>::iterator result = easyfind(myList, MAX_VAL + 1);
		std::cout << "Found: " << *result << std::endl;
	}
	catch (const NotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Test 3: container: Stack
	std::cout << GRAY << "\n-- test 3 (container: stack) --" << RESET << std::endl;

	std::stack<std::string> myStack;

	myStack.push("one");
	myStack.push("two");
	myStack.push("three");

	std::deque<std::string> stackContainer;
	while (!myStack.empty())
	{
		stackContainer.push_front(myStack.top());
		myStack.pop();
	}

	try
	{
		std::cout << "Attempting to find element: 'two'..." << std::endl;
		std::deque<std::string>::iterator result = easyfind(stackContainer, std::string("two"));
		std::cout << "Found: " << *result << std::endl;
	}
	catch (const NotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Attempting to find element: 'four'..." << std::endl;
		std::deque<std::string>::iterator result = easyfind(stackContainer, std::string("four"));
		std::cout << "Found: " << *result << std::endl;
	}
	catch (const NotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}
