/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:38:12 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/05 12:05:34 by dklimkin         ###   ########.fr       */
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

static bool	isValidName(std::string input) {
	for (std::string::iterator c=input.begin(); c != input.end(); ++c) {
		if (!std::isalpha((*c)))
			return (false);
	}
	return (true);
}

static bool	isValidPhoneNumber(std::string input) {
	for (std::string::iterator c=input.begin(); c != input.end(); ++c) {
		if (!std::isdigit((*c)))
			return (false);
	}
	return (true);
}

static std::string	getFieldValue(std::string prompt, t_inputTypes inputType) {
	std::string input;
	bool		isError;

    do {
		isError = false;
        std::cout << prompt;
        std::getline(std::cin, input);
		isError = input.empty();
        if (isError) {
			std::cout << ERROR_PREFIX << EMPTY_FIELD_ERR << std::endl;
			continue;
		}
		isError = inputType == NAME && !isValidName(input);
		if (isError) {
			std::cout << ERROR_PREFIX << NOT_ALPHA_ERR << std::endl;
			continue;
		}
		isError = inputType == PHONE && !isValidPhoneNumber(input);
		if (isError) {
			std::cout << ERROR_PREFIX << NOT_NUM_ERR << std::endl;
			continue;
		}
    } while (isError);

    return (input);
}

void	Contact::createContact(void) {
	this->_firstName = getFieldValue(FIRST_NAME_PROMPT, NAME);
	this->_lastName = getFieldValue(LAST_NAME_PROMPT, NAME);
	this->_nickname = getFieldValue(NICKNAME_PROMPT, DEFAULT);
	this->_phoneNumber = getFieldValue(PHONE_NUMBER_PROMPT, PHONE);
	this->_darkestSecret = getFieldValue(DARKEST_SECRET_PROMPT, DEFAULT);

	std::cout << CONTACT_ADDED_MSG << std::endl;
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
