/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:12:46 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/05 12:08:46 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "constants.hpp"
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		PhoneBook(const PhoneBook &other);
		~PhoneBook();
		PhoneBook & operator=(const PhoneBook &other);

		void	addContact(Contact contact);
		void	showContacts(void);

	private:
		Contact _contacts[MAX_NUMBER_OF_CONTACTS];
		int 	_numberOfContacts;
};

#endif
