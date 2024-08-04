#ifndef ROBOTOMY_REQUEST_FROM_HPP
#define ROBOTOMY_REQUEST_FROM_HPP

#include "AForm.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	static const int _REQUIRED_GRADE_TO_SIGN = 72;
	static const int _REQUIRED_GRADE_TO_EXECUTE = 45;

	const std::string _target;

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	void execute(Bureaucrat &bureaucrat);

	class FailedToRobotomizeException : public std::exception
	{
	public:
		virtual const char *what() const throw() { return "Robotomy failed"; }
	};
};

#endif
