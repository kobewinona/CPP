#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>

#define RESET "\033[0m"
#define GRAY "\033[90m"

int main(void) {
  std::cout << GRAY << "\n-- test 1 --" << RESET << std::endl;
  try {
    Bureaucrat bimmy("Bimmy", 2);
    Form formA("Form with a ridiculous unnecessarily long name", 3, 5);
    std::cout << formA << std::endl;

    bimmy.signForm(formA);
    std::cout << formA << std::endl;

    Bureaucrat jimmy("Jimmy", 4);
    Form formB("Form B", 3, 5);

    std::cout << formB << std::endl;

    jimmy.signForm(formB);
    std::cout << formB << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
