#ifndef FORM_HPP
#define FORM_HPP

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

class Form
{
private:
	const std::string _name;
	const int _requiredGradeToSign;
	const int _requiredGradeToExecute;
	bool _isSigned;

public:
	Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	// @defgroup get/set functions
	const std::string getName() const;
	int getRequiredGradeToSign() const;
	int getRequiredGradeToExecute() const;
	bool getIsFormSigned() const;

	// @defgroup member functions
	void beSigned(Bureaucrat &bureaucrat);

	// @defgroup exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw() { return "Grade too high"; }
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw() { return "Grade too low"; }
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
