#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern {
private:
  struct _forms {
    std::string formName;
    AForm *(*createForm)(const std::string &target);
  };

  static const _forms formCreators[];

public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(std::string formName, std::string target);
  
  class UnknownFormException : public std::exception {
  private:
    std::string _message;

  public:
    UnknownFormException(const std::string &formName) {
      _message = "Form `" + formName + "` is unknown";
    }
    virtual ~UnknownFormException() throw() {}
    virtual const char *what() const throw() { return _message.c_str(); }
  };
};

#endif // INTERN_HPP
