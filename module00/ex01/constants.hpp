/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:02:17 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/05 12:08:25 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#define MAX_NUMBER_OF_CONTACTS 8
#define MAX_FIELD_SIZE 10

#define FIRST_NAME_PROMPT "Enter first name: "
#define LAST_NAME_PROMPT "Enter last name: "
#define NICKNAME_PROMPT "Enter nickname: "
#define PHONE_NUMBER_PROMPT "Enter phone number: "
#define DARKEST_SECRET_PROMPT "Enter your \033[35mdarkest secret\033[0m: "

#define CONTACT_ADDED_MSG "\n\033[32mContact was succesfully added\033[0\n"

#define ERROR_PREFIX "\033[31mError:\033[0m "
#define EMPTY_FIELD_ERR "Field should not be empty\n"
#define NOT_ALPHA_ERR "Field should contain only alphabetic characters\n"
#define NOT_NUM_ERR "Field should contain only numeric characters\n"

typedef enum s_enum {
	DEFAULT,
	NAME,
	PHONE,
}	t_inputTypes;

#endif