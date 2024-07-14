#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", _REQUIRED_GRADE_TO_SIGN,
            _REQUIRED_GRADE_TO_EXECUTE),
      _target(target){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other)
    AForm::operator=(other);

  return (*this);
}

// @def destructor
ShrubberyCreationForm::~ShrubberyCreationForm(){};

// @defgroup member functions
void ShrubberyCreationForm::execute(Bureaucrat &bureaucrat) {
  _validateExecution(bureaucrat);

  std::string fileName = _target + "_shrubberry";
  std::ofstream outFile(fileName.c_str());
  if (!outFile)
    throw FailedToCreateFileException();

  outFile << TREE;
  outFile.close();
};
