/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myPhonebook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:25:22 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/09 11:59:50 by dklimkin         ###   ########.fr       */
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

	do {
		if (!input.compare("ADD")) {
			phoneBook.addContact();
		} else if (!input.compare("SEARCH")) {
			phoneBook.handleSearch();
		} else if (!input.compare("EXIT")) {
			return (EXIT_SUCCESS);
		} else {
			printPrompt();
		}

		std::cout << "> ";
		std::getline(std::cin, input);
	} while (!std::cin.eof());

	return (EXIT_SUCCESS);
}
