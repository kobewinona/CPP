#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", _REQUIRED_GRADE_TO_SIGN,
            _REQUIRED_GRADE_TO_EXECUTE),
      _target(target) {
  std::srand(std::time(0));
};

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other)
    AForm::operator=(other);

  return (*this);
}

// @def destructor
PresidentialPardonForm::~PresidentialPardonForm(){};

// @defgroup member functions
void PresidentialPardonForm::execute(Bureaucrat &bureaucrat) {
  _validateExecution(bureaucrat);

  std::cout << _target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
};
