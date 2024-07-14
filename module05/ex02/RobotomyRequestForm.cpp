#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", _REQUIRED_GRADE_TO_SIGN,
            _REQUIRED_GRADE_TO_EXECUTE),
      _target(target) {
  std::srand(std::time(0));
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other)
    AForm::operator=(other);

  return (*this);
}

// @def destructor
RobotomyRequestForm::~RobotomyRequestForm(){};

// @defgroup member functions
void RobotomyRequestForm::execute(Bureaucrat &bureaucrat) {
  _validateExecution(bureaucrat);

  std::cout << "making drilling noises..." << std::endl;
  system("say wroom wroom wroom");

  if (std::rand() % 2)
    std::cout << _target << " has been robotomized successfully!" << std::endl;
  else
    throw FailedToRobotomizeException();
};
