/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:12:46 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/04 21:25:47 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "myPhonebook.hpp"

class PhoneBook {
	public:
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		~PhoneBook();
		PhoneBook& operator=(const PhoneBook& other);

		int addContact(int contact);

	private:
		int contacts[8];
		int numberOfContacts;
};

#endif