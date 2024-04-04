/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myPhonebook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:25:22 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/04 21:38:32 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myPhonebook.hpp"

void	print_prompt(void) {
	std::cout << "\033[90m\n";
	std::cout << "\033[1mADD\033[22m    - save a new contact.\n";
    std::cout << "\033[1mSEARCH\033[22m - display a specific contact. (Not implemented yet)\n";
    std::cout << "\033[1mEXIT\033[22m   - exit the program.\n" << std::endl;
	std::cout << "\033[0m";

	std::cout << "> ";
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	userInput;
	int			contactNumber;

	while (true) {
		print_prompt();
		std::cin >> userInput;

		if (!userInput.compare("ADD")) {
			std::cout << "Enter contact number to add: ";
			std::cin >> contactNumber;
			phoneBook.addContact(contactNumber);
		}

		if (!userInput.compare("EXIT")) {
			return (EXIT_SUCCESS);
		}
	}

	return (EXIT_SUCCESS);
}
