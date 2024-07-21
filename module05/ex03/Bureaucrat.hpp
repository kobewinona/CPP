#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  // @defgroup get/set functions
  const std::string getName() const;
  int getGrade() const;

  // @defgroup member functions
  void incrementGrade();
  void decrementGrade();
  void signForm(AForm &form);
  void executeForm(AForm &form);

  // @defgroup exceptions
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade too low"; }
  };

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade too high"; }
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP
