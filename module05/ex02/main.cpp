#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

#define RESET "\033[0m"
#define GRAY "\033[90m"

int main(void) {
  Bureaucrat bimmy("Bimmy", 70);
  Bureaucrat jimmy("Jimmy", 20);
  Bureaucrat zitz("Zitz", 2);

  ShrubberyCreationForm tree("Foggyland");
  std::cout << tree << std::endl;

  RobotomyRequestForm robo("Bimmy");
  std::cout << robo << std::endl;

  PresidentialPardonForm PP("Jimmy");
  std::cout << PP << std::endl;

  std::cout << GRAY << "\n-- test 1 --" << RESET << std::endl;
  try {
    bimmy.signForm(tree);
    std::cout << tree << std::endl;

    bimmy.executeForm(tree);
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  std::cout << GRAY << "\n-- test 2 --" << RESET << std::endl;
  try {
    bimmy.signForm(robo);
    std::cout << robo << std::endl;

    jimmy.executeForm(robo);
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  std::cout << GRAY << "\n-- test 3 --" << RESET << std::endl;
  try {
    zitz.signForm(PP);
    std::cout << PP << std::endl;

    zitz.executeForm(PP);
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
