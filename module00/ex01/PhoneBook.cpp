/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:13:24 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/05 12:09:59 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _numberOfContacts(0) {}

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

void	PhoneBook::addContact(Contact contact) {
	if (_numberOfContacts >= 8)
		_numberOfContacts = 0;
    if (_numberOfContacts < 8)
        _contacts[_numberOfContacts++] = contact;
}

static std::string getFormattedFieldValue(const std::string& fieldValue) {
    std::string formattedFieldValue = fieldValue;

    if (formattedFieldValue.length() > MAX_FIELD_SIZE) {
		formattedFieldValue.resize(MAX_FIELD_SIZE - 1);
        formattedFieldValue += '.';
    }
    return (formattedFieldValue);
}

void	PhoneBook::showContacts(void) {
	std::cout	<< "\033[1m" << std::setw(MAX_FIELD_SIZE) << "Index" << "\033[0m" << " | "
				<< "\033[1m" << std::setw(MAX_FIELD_SIZE) << "First Name" << "\033[0m" << " | "
				<< "\033[1m" << std::setw(MAX_FIELD_SIZE) << "Last Name" << "\033[0m" << " | "
				<< "\033[1m" << std::setw(MAX_FIELD_SIZE) << "Nickname" << "\033[0m" << std::endl;

	for (int i = 0; i < _numberOfContacts; ++i) {
		std::cout	<< std::setw(MAX_FIELD_SIZE)
					<< i << " | "
					<< std::setw(MAX_FIELD_SIZE)
					<< getFormattedFieldValue(_contacts[i].getFirstName()) << " | "
					<< std::setw(MAX_FIELD_SIZE)
					<< getFormattedFieldValue(_contacts[i].getLastName()) << " | "
					<< std::setw(MAX_FIELD_SIZE)
					<< getFormattedFieldValue(_contacts[i].getNickname()) << std::endl;
	}
}
