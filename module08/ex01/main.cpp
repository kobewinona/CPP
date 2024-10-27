#include "Span.hpp"
#include <cstdlib>
#include <iostream>

#define RESET "\033[0m"
#define GRAY "\033[90m"

#define TEST_SPAN_LIMIT 15000

int main(int argc, char **argv) {
  // Test 1: Small span
  std::cout << GRAY << "\n-- test 1 (small span) --" << RESET << std::endl;

  try {
    Span sp1(5);

    sp1.addNumber(6);
    sp1.addNumber(3);
    sp1.addNumber(17);
    sp1.addNumber(9);
    sp1.addNumber(11);

    std::cout << "Shortest Span: " << sp1.shortestSpan()
              << std::endl; // Expected: 2
    std::cout << "Longest Span: " << sp1.longestSpan()
              << std::endl; // Expected: 14

    std::cout << "Trying to add more numbers than the limit..." << std::endl;
    sp1.addNumber(60); // This should throw a SpanFullException
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // Test 2: Large span with more than 10,000 numbers
  std::cout << GRAY << "\n-- test 2 (large span: 10,000+ random numbers) --";
  std::cout << RESET << std::endl;

  srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
  try {
    Span sp2(TEST_SPAN_LIMIT);

    // Add 10,001 random numbers
    for (int i = 0; i < TEST_SPAN_LIMIT; ++i)
      sp2.addNumber(rand() % 1000000); // Random number between 0 and 999,999

    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (argc <= 1) {
    std::cout << std::endl;
    return EXIT_SUCCESS;
  }

  // Test 3: Span with provided values
  std::cout << GRAY << "\n-- test 3 (span with provided values) --";
  std::cout << RESET << std::endl;
  
  Span sp3(argc - 1);
  std::vector<int> providedValued;
  for (int i = 1; i < argc; ++i)
    providedValued.push_back(std::atoi(argv[i]));

  try {
    sp3.addNumbers(providedValued.begin(), providedValued.end());

    std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;
  return EXIT_SUCCESS;
}