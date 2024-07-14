#ifndef PRESEDENTIAL_PARDON_FROM_HPP
#define PRESEDENTIAL_PARDON_FROM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
  static const int _REQUIRED_GRADE_TO_SIGN = 25;
  static const int _REQUIRED_GRADE_TO_EXECUTE = 5;

  const std::string _target;

public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();

  void execute(Bureaucrat &bureaucrat);
};

#endif
