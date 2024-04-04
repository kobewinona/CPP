/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:13:24 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/04 21:29:17 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : numberOfContacts(0) {}
PhoneBook::~PhoneBook() {}

int	PhoneBook::addContact(int contact) {
    if (numberOfContacts < 8) {
        contacts[numberOfContacts++] = contact;
		return (SUCCESS);
    }
	std::cout << "PhoneBook is full." << std::endl;
	return (FAILURE);
}