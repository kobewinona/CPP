#include "MutantStack.hpp"
#include <cstdlib>
#include <iostream>

#define RESET "\033[0m"
#define GRAY "\033[90m"

#define TEST_SPAN_LIMIT 15000

int main(int argc, char **argv)
{
	(void)argv;
	// Test 1: Basic test with fixed integer values
	std::cout << GRAY << "\n-- test 1 (fixed int values) --";
	std::cout << RESET << std::endl;

	MutantStack<int> mstack1;

	mstack1.push(5);
	mstack1.push(17);

	std::cout << "Top element: " << mstack1.top() << std::endl; // Expected: 17

	mstack1.pop();

	std::cout << "Size after pop: " << mstack1.size() << std::endl; // Expected: 1

	mstack1.push(3);
	mstack1.push(5);
	mstack1.push(737);
	mstack1.push(0);

	// Iterating through the stack using iterators
	for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end();
		 ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl; // Expected: 5 3 5 737 0

	// Test 2: Basic test with std::string values
	std::cout << GRAY << "\n-- test 1 (fixed std::string values) --";
	std::cout << RESET << std::endl;

	MutantStack<std::string> mstack2;

	mstack2.push("hello");
	mstack2.push(", ");
	mstack2.push("world");
	mstack2.push("!");

	for (MutantStack<std::string>::iterator it = mstack2.begin();
		 it != mstack2.end(); ++it)
	{
		std::cout << *it;
	}
	std::cout << std::endl; // Expected: "hello, world!"

	if (argc <= 1)
	{
		std::cout << std::endl;
		return EXIT_SUCCESS;
	}

	// Test 3: Span with provided values
	std::cout << GRAY << "\n-- test 3 (iteration through provided values) --";
	std::cout << RESET << std::endl;

	MutantStack<std::string> argvStack;

	for (int i = 1; i < argc; ++i)
	{
		argvStack.push(argv[i]);
	}

	for (MutantStack<std::string>::iterator it = argvStack.begin();
		 it != argvStack.end(); ++it)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
