/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:36:44 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/09 11:41:08 by dklimkin         ###   ########.fr       */
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

		int			createContact(void);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
		void		showContactDetails(int index);
		Contact		getContactDetails(void);

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string _nickname;
		std::string	_phoneNumber;
		std::string _darkestSecret;

		bool		_isValidName(std::string input);
		bool		_isValidPhoneNumber(std::string input);
		std::string	_getFieldValue(std::string prompt, t_inputTypes inputType);
};

#endif
