/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:13:24 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/09 12:15:34 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _numberOfContacts(0), _nextContactIndex(0) {}

PhoneBook::PhoneBook(const PhoneBook &other) {
	for (int i = 0; i < MAX_NUMBER_OF_CONTACTS; ++i)
		this->_contacts[i] = other._contacts[i];
}

PhoneBook::~PhoneBook() {}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
	for (int i = 0; i < MAX_NUMBER_OF_CONTACTS; ++i)
		this->_contacts[i] = other._contacts[i];
	return ((*this));
}

void	PhoneBook::addContact(void) {
	if (_nextContactIndex >= MAX_NUMBER_OF_CONTACTS) _nextContactIndex = 0;

	if (_numberOfContacts < MAX_NUMBER_OF_CONTACTS) _numberOfContacts++;

	if (_contacts[_nextContactIndex].createContact() == FAILURE) return;
	_nextContactIndex++;

	std::cout	<< "\n" << CONTACT_ADDED_MSG << "\n"
				<< "\033[90m" << NUMBER_OF_CONTACTS << _numberOfContacts << "\033[0m"
				<< "\n" << std::endl;
}

static std::string getFormattedFieldValue(const std::string& fieldValue) {
    std::string formattedFieldValue = fieldValue;

    if (formattedFieldValue.length() > MAX_FIELD_SIZE) {
		formattedFieldValue.resize(MAX_FIELD_SIZE - 1);
        formattedFieldValue += '.';
    }
    return (formattedFieldValue);
}

void	PhoneBook::_showContacts(void) {
	std::cout	<< "\n\033[1m" << std::setw(MAX_FIELD_SIZE) << "Index" << "\033[0m" << " | "
				<< "\033[1m" << std::setw(MAX_FIELD_SIZE) << "First Name" << "\033[0m" << " | "
				<< "\033[1m" << std::setw(MAX_FIELD_SIZE) << "Last Name" << "\033[0m" << " | "
				<< "\033[1m" << std::setw(MAX_FIELD_SIZE) << "Nickname" << "\033[0m" << std::endl;

	for (int i = 0; i < MAX_NUMBER_OF_CONTACTS && i < _numberOfContacts; ++i) {
		std::cout	<< std::setw(MAX_FIELD_SIZE)
					<< (i + 1) << " | "
					<< std::setw(MAX_FIELD_SIZE)
					<< getFormattedFieldValue(_contacts[i].getFirstName()) << " | "
					<< std::setw(MAX_FIELD_SIZE)
					<< getFormattedFieldValue(_contacts[i].getLastName()) << " | "
					<< std::setw(MAX_FIELD_SIZE)
					<< getFormattedFieldValue(_contacts[i].getNickname()) << std::endl;
	}
}

void	PhoneBook::_showContact(Contact contact) {
	std::cout << "First name: " << contact.getFirstName() << "\n";
	std::cout << "Last name: " << contact.getLastName() << "\n";
	std::cout << "Nickname: " << contact.getNickname() << "\n";
	std::cout << "Phone number: " << contact.getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << "\n\n";
}

void	PhoneBook::handleSearch(void) {
	std::string	input;
	long long	index;
	bool		isError;

	if (_numberOfContacts == 0) {
		std::cout << "\n" << NO_CONTACTS_MSG << "\n" << std::endl;
		return;
	}

	_showContacts();

	do {
		isError = false;
		std::cout << "\n" << SEARCH_INDEX_PROMPT;
    	std::getline(std::cin, input);

		if (std::cin.eof()) return;

		std::istringstream iss(input);

		if (!input.compare("q")) {
			std::cout << std::endl;
			return;
		}

		if (!(iss >> index) || !iss.eof() || index < 1 || index > _numberOfContacts) {
			isError = true;
			std::cerr << ERROR_PREFIX << INVALID_INDEX_ERR << _numberOfContacts << "\n" << std::endl;
			continue;
		}
	} while (isError);

	std::cout << "\n" << "\033[1m" << "- Contact #" << index << " -\033[0m" << std::endl;
	_showContact(_contacts[index - 1]);
}
