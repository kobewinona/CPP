#include "whatever.hpp"
#include <cstdlib>
#include <iostream>

#define RESET "\033[0m"
#define GRAY "\033[90m"

int main() {
  // Test swap
  std::cout << GRAY << "\n-- test 1 (swap int) --" << RESET << std::endl;
  int a = 5, b = 10;
  std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
  swap(a, b);
  std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

  std::cout << GRAY << "\n-- test 2 (swap double) --" << RESET << std::endl;
  double x = 3.14, y = 2.71;
  std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
  swap(x, y);
  std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

  std::cout << GRAY << "\n-- test 3 (swap string) --" << RESET << std::endl;
  std::string str1 = "Hello", str2 = "World";
  std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2
            << std::endl;
  ::swap(str1, str2);
  std::cout << "After swap: str1 = " << str1 << ", str2 = " << str2
            << std::endl;

  // Test min
  std::cout << GRAY << "\n-- test 1 (min int) --" << RESET << std::endl;
  std::cout << "Min of 5 and 10: " << ::min(5, 10) << std::endl;

  std::cout << GRAY << "\n-- test 2 (min double) --" << RESET << std::endl;
  std::cout << "Min of 3.14 and 2.71: " << ::min(3.14, 2.71) << std::endl;

  std::cout << GRAY << "\n-- test 3 (min string) --" << RESET << std::endl;
  std::cout << "Min of \"apple\" and \"banana\": "
            << ::min(std::string("apple"), std::string("banana")) << std::endl;

  // Test max
  std::cout << GRAY << "\n-- test 1 (max int) --" << RESET << std::endl;
  std::cout << "Max of 5 and 10: " << ::max(5, 10) << std::endl;

  std::cout << GRAY << "\n-- test 2 (max double) --" << RESET << std::endl;
  std::cout << "Max of 3.14 and 2.71: " << ::max(3.14, 2.71) << std::endl;

  std::cout << GRAY << "\n-- test 3 (max string) --" << RESET << std::endl;
  std::cout << "Max of \"apple\" and \"banana\": "
            << ::max(std::string("apple"), std::string("banana")) << std::endl;
  return EXIT_SUCCESS;
}