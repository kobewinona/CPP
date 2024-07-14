#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade too low"; }
  };

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade too high"; }
  };

  const std::string getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif