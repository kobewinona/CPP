#include "AForm.hpp"

static std::string getFormattedFieldValue(const std::string &fieldValue) {
  std::string formattedFieldValue = fieldValue;

  if (formattedFieldValue.length() > MAX_NAME_FIELD_LENGTH) {
    formattedFieldValue.resize(MAX_NAME_FIELD_LENGTH - 3);
    formattedFieldValue += "...";
  }
  return (formattedFieldValue);
}

// @defgroup constructors
AForm::AForm(std::string name, int requiredGradeToSign,
             int requiredGradeToExecute)
    : _name(name), _requiredGradeToSign(requiredGradeToSign),
      _requiredGradeToExecute(requiredGradeToExecute), _isSigned(false){};

AForm::AForm(const AForm &other)
    : _name(other._name), _requiredGradeToSign(other._requiredGradeToSign),
      _requiredGradeToExecute(other._requiredGradeToExecute),
      _isSigned(other._isSigned){};

AForm &AForm::operator=(const AForm &other) {
  if (this != &other)
    _isSigned = other._isSigned;

  return (*this);
};

// @def destructor
AForm::~AForm(){};

// @defgroup get/set functions
const std::string AForm::getName() const { return _name; }
int AForm::getRequiredGradeToSign() const { return _requiredGradeToSign; }
int AForm::getRequiredGradeToExecute() const { return _requiredGradeToExecute; }
bool AForm::getIsFormSigned() const { return _isSigned; }

// @defgroup member functions
void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _requiredGradeToSign)
    throw GradeTooLowException();
  _isSigned = true;
}

void AForm::_validateExecution(const Bureaucrat &bureaucrat) const {
  if (!_isSigned) {
    throw NotSignedToBeExecutedException();
  }
  if (bureaucrat.getGrade() > _requiredGradeToExecute) {
    throw GradeTooLowException();
  }
}

// @defgroup overload
std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << BOLD << std::left << std::setw(MAX_NAME_FIELD_LENGTH) << "Form Name"
     << " | " << std::setw(14) << "Sign Grade"
     << " | " << std::setw(14) << "Execute Grade"
     << " | " << std::setw(10) << "Signed" << RESET << std::endl;

  os << std::left << std::setw(MAX_NAME_FIELD_LENGTH)
     << getFormattedFieldValue(form.getName()) << " | " << std::setw(14)
     << form.getRequiredGradeToSign() << " | " << std::setw(14)
     << form.getRequiredGradeToExecute() << " | " << std::setw(10)
     << (form.getIsFormSigned() ? GREEN "Yes" RESET : RED "No" RESET)
     << std::endl;

  return os;
}
