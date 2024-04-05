/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myPhonebook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:25:22 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/05 10:45:51 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myPhonebook.hpp"

void	printPrompt(void) {
	std::cout	<< "\033[90m"
				<< "\033[1m\nADD\033[22m    - save a new contact.\n"
    			<< "\033[1mSEARCH\033[22m - display a specific contact. (Not implemented yet)\n"
    			<< "\033[1mEXIT\033[22m   - exit the program.\n"
				<< "\033[0m"
				<< std::endl << "> ";
}

int	main(void) {
	PhoneBook	phoneBook;
	std::string	input;

	while (true) {
		printPrompt();
		std::getline(std::cin, input);

		if (!input.compare("ADD")) {
			Contact		contact;
			contact.createContact();
			phoneBook.addContact(contact);
		}

		if (!input.compare("SEARCH")) {
			phoneBook.showContacts();
		}

		if (!input.compare("EXIT")) {
			return (EXIT_SUCCESS);
		}
	}

	return (EXIT_SUCCESS);
}
