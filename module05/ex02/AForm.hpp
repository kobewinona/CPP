#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iomanip>
#include <string>

#define RESET "\033[0m"
#define GRAY "\033[90m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BOLD "\033[1m"
#define NORMAL "\033[22m"
#define MAX_NAME_FIELD_LENGTH 20

class Bureaucrat;

class AForm {
protected:
  const std::string _name;
  const int _requiredGradeToSign;
  const int _requiredGradeToExecute;
  bool _isSigned;

  void _validateExecution(const Bureaucrat &bureaucrat) const;

public:
  AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  // @defgroup get/set functions
  const std::string getName() const;
  int getRequiredGradeToSign() const;
  int getRequiredGradeToExecute() const;
  bool getIsFormSigned() const;

  // @defgroup member functions
  void beSigned(Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat &bureaucrat) = 0;

  // @defgroup exceptions
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high"; }
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low"; }
  };
  class NotSignedToBeExecutedException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Form is not signed"; }
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
