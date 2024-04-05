/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myPhonebook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:25:22 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/05 14:06:19 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myPhonebook.hpp"

void	printPrompt(void) {
	std::cout	<< "\033[90m" << "\n" << "User commands" << "\n\n" << std::left
				<< "\033[1m" << std::setw(10) << "ADD" << "\033[22m" << ADD_CMD_PROMPT
    			<< "\033[1m" << std::setw(10) << "SEARCH" << "\033[22m" << SEARCH_CMD_PRMOPT
    			<< "\033[1m" << std::setw(10) << "EXIT" << "\033[22m" << EXIT_CMD_PROMPT
				<< "\033[0m" << std::right << std::endl;
}

int	main(void) {
	PhoneBook	phoneBook;
	std::string	input;

	printPrompt();
	while (true) {
		std::cout << "> ";
		std::getline(std::cin, input);

		if (!input.compare("ADD")) {
			Contact		contact;
			contact.createContact();
			phoneBook.addContact(contact);
		} else if (!input.compare("SEARCH")) {
			phoneBook.handleSearch();
		} else if (!input.compare("EXIT")) {
			return (EXIT_SUCCESS);
		} else {
			printPrompt();
		}
	}

	return (EXIT_SUCCESS);
}
