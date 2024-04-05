/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:36:44 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/05 12:05:31 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <limits>
#include <string>
#include "constants.hpp"

class Contact {
	public:
		Contact();
		Contact(const Contact& other);
		~Contact();
		Contact& operator=(const Contact& other);

		void		createContact(void);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string _nickname;
		std::string	_phoneNumber;
		std::string _darkestSecret;
};

#endif
