#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>

#define RESET "\033[0m"
#define GRAY "\033[90m"

int main(void) {
  Bureaucrat bimmy("Bimmy", 70);
  Bureaucrat jimmy("Jimmy", 20);
  Bureaucrat zitz("Zitz", 2);
  Intern chuck;

  std::cout << GRAY << "\n-- test 1 --" << RESET << std::endl;
  AForm *tree = NULL;

  try {
    tree = chuck.makeForm("Shrubbery Creation", "FoggyLand");
    std::cout << (*tree) << std::endl;
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  if (tree) {
    bimmy.signForm((*tree));
    std::cout << ((*tree)) << std::endl;
    bimmy.executeForm(*tree);
  }

  std::cout << GRAY << "\n-- test 2 --" << RESET << std::endl;
  AForm *robo = NULL;

  try {
    robo = chuck.makeForm("Robotomy Request", "Bimmy");
    std::cout << (*robo) << std::endl;
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  if (robo) {
    bimmy.signForm((*robo));
    std::cout << (*robo) << std::endl;
    jimmy.executeForm((*robo));
  }

  std::cout << GRAY << "\n-- test 3 --" << RESET << std::endl;
  AForm *PP = NULL;

  PP = chuck.makeForm("Presidential Pardon", "Jimmy");

  if (PP) {
    zitz.signForm((*PP));
    std::cout << (*PP) << std::endl;
    zitz.executeForm((*PP));
  }

  return delete tree, delete robo, delete PP, EXIT_SUCCESS;
};
