#include "Bureaucrat.hpp"
#include <cstdlib>

#define RESET "\033[0m"
#define GRAY "\033[90m"

int main(void) {
  std::cout << GRAY << "\n-- test 1 --" << RESET << std::endl;
  try {
    Bureaucrat bimmy("Bimmy", 2);
    std::cout << bimmy << std::endl;

    bimmy.incrementGrade();
    std::cout << bimmy << std::endl;

    bimmy.incrementGrade();
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  std::cout << GRAY << "\n-- test 2 --" << RESET << std::endl;
  try {
    Bureaucrat jimmy("Jimmy", 151);
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  return EXIT_SUCCESS;
}