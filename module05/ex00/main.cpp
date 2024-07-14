#include "Bureaucrat.hpp"
#include <cstdlib>

#define RESET "\033[0m"
#define GRAY "\033[90m"

int main(void) {
  std::cout << GRAY << "\n-- test 1 --" << RESET << std::endl;
  try {
    Bureaucrat bob("Bimmy", 2);
    std::cout << bob << std::endl;

    bob.incrementGrade();
    std::cout << bob << std::endl;

    bob.incrementGrade();
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  std::cout << GRAY << "\n-- test 2 --" << RESET << std::endl;
  try {
    Bureaucrat alice("Jimmy", 151);
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  return EXIT_SUCCESS;
}