#include "Intern.hpp"

static AForm *createShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
};

static AForm *createRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
};

static AForm *createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
};

// Initialize the formCreators array
const Intern::_forms Intern::formCreators[] = {
	{"shrubbery creation", createShrubberyForm},
	{"robotomy request", createRobotomyForm},
	{"presidential pardon", createPresidentialPardonForm}};

// @defgroup constructors
Intern::Intern(){};
Intern::Intern(const Intern &other) { (*this) = other; };
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
};

// @def destructor
Intern::~Intern(){};

std::string toLowerCase(const std::string &str)
{
	std::string lowerStr = str;

	for (size_t i = 0; i < lowerStr.length(); ++i)
		lowerStr[i] = std::tolower(static_cast<unsigned char>(lowerStr[i]));

	return lowerStr;
}

// @defgroup member functions
AForm *Intern::makeForm(std::string formName, std::string target)
{
	for (size_t i = 0; i < sizeof(formCreators) / sizeof(formCreators[0]); ++i)
	{
		if (formCreators[i].formName == toLowerCase(formName))
			return formCreators[i].createForm(target);
	}
	throw UnknownFormException(formName.c_str());
};
