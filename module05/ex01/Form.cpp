#include "Form.hpp"

static std::string getFormattedFieldValue(const std::string &fieldValue) {
  std::string formattedFieldValue = fieldValue;

  if (formattedFieldValue.length() > MAX_NAME_FIELD_LENGTH) {
    formattedFieldValue.resize(MAX_NAME_FIELD_LENGTH - 3);
    formattedFieldValue += "...";
  }
  return (formattedFieldValue);
}

// @defgroup constructors
Form::Form(std::string name, int requiredGradeToSign,
           int requiredGradeToExecute)
    : _name(name), _requiredGradeToSign(requiredGradeToSign),
      _requiredGradeToExecute(requiredGradeToExecute), _isSigned(false){};

Form::Form(const Form &other)
    : _name(other._name), _requiredGradeToSign(other._requiredGradeToSign),
      _requiredGradeToExecute(other._requiredGradeToExecute),
      _isSigned(other._isSigned){};

Form &Form::operator=(const Form &other) {
  if (this != &other)
    _isSigned = other._isSigned;

  return (*this);
};

// @def destructor
Form::~Form(){};

// @defgroup get/set functions
const std::string Form::getName() const { return _name; }
int Form::getRequiredGradeToSign() const { return _requiredGradeToSign; }
int Form::getRequiredGradeToExecute() const { return _requiredGradeToExecute; }
bool Form::getIsFormSigned() const { return _isSigned; }

// @defgroup member functions
void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _requiredGradeToSign)
    throw GradeTooLowException();
  _isSigned = true;
}

// @defgroup overload
std::ostream &operator<<(std::ostream &os, const Form &form) {
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
