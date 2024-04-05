/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:38:12 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/05 14:14:16 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : 
    _firstName(""),
    _lastName(""),
    _nickname(""),
    _phoneNumber(""),
    _darkestSecret("") {}

Contact::Contact(const Contact& other) : 
    _firstName(other._firstName),
    _lastName(other._lastName),
    _nickname(other._nickname),
    _phoneNumber(other._phoneNumber),
    _darkestSecret(other._darkestSecret) {}

Contact::~Contact() {}

Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        _firstName = other._firstName;
        _lastName = other._lastName;
        _nickname = other._nickname;
        _phoneNumber = other._phoneNumber;
        _darkestSecret = other._darkestSecret;
    }
    return (*this);
}

bool	Contact::_isValidName(std::string input) {
	for (std::string::iterator c=input.begin(); c != input.end(); ++c) {
		if (!std::isalpha((*c)))
			return (false);
	}
	return (true);
}

bool	Contact::_isValidPhoneNumber(std::string input) {
	for (std::string::iterator c=input.begin(); c != input.end(); ++c) {
		if (!std::isdigit((*c)))
			return (false);
	}
	return (true);
}

std::string	Contact::_getFieldValue(std::string prompt, t_inputTypes inputType) {
	std::string input;
	bool		isError;

    do {
		isError = false;
        std::cout << prompt;
        std::getline(std::cin, input);
		isError = input.empty();
        if (isError) {
			std::cerr << ERROR_PREFIX << EMPTY_FIELD_ERR << "\n" << std::endl;
			continue;
		}
		isError = (inputType == NAME && !_isValidName(input));
		if (isError) {
			std::cerr << ERROR_PREFIX << NOT_ALPHA_ERR << "\n" <<std::endl;
			continue;
		}
		isError = (inputType == PHONE && !_isValidPhoneNumber(input));
		if (isError) {
			std::cerr << ERROR_PREFIX << NOT_NUM_ERR << "\n" <<std::endl;
			continue;
		}
    } while (isError);

    return (input);
}

void	Contact::createContact(void) {
	this->_firstName = _getFieldValue(FIRST_NAME_PROMPT, NAME);
	this->_lastName = _getFieldValue(LAST_NAME_PROMPT, NAME);
	this->_nickname = _getFieldValue(NICKNAME_PROMPT, DEFAULT);
	this->_phoneNumber = _getFieldValue(PHONE_NUMBER_PROMPT, PHONE);
	this->_darkestSecret = _getFieldValue(DARKEST_SECRET_PROMPT, DEFAULT);
}

std::string	Contact::getFirstName(void) {
	return (this->_firstName);
}

std::string	Contact::getLastName(void) {
	return (this->_lastName);
}

std::string	Contact::getNickname(void) {
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) {
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) {
	return (this->_darkestSecret);
}

void	Contact::showContactDetails(int index) {
	std::cout << "\n" << "\033[1mContact #" << index << "\033[0m\n" << std::endl;
	std::cout << "First name: " << this->_firstName << "\n";
	std::cout << "Last name: " << this->_lastName << "\n";
	std::cout << "Nickname: " << this->_nickname << "\n";
	std::cout << "Phone number: " << this->_phoneNumber << "\n";
	std::cout << "Darkest secret: " << this->_darkestSecret << "\n\n";
}