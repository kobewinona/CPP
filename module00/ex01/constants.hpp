/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:02:17 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/05 14:03:11 by dklimkin         ###   ########.fr       */
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
#define SEARCH_INDEX_PROMPT "Enter Phone book index: "

#define ADD_CMD_PROMPT "save a new contact\n"
#define SEARCH_CMD_PRMOPT "display a specific contact\n"
#define EXIT_CMD_PROMPT "exit the program\n"

#define NUMBER_OF_CONTACTS "Total number of contacts: "

#define CONTACT_ADDED_MSG "\033[32mContact was succesfully added\033[0m"
#define NO_CONTACTS_MSG "\033[33mPhone book is empty\033[0m"

#define ERROR_PREFIX "\033[31mError:\033[0m "
#define EMPTY_FIELD_ERR "Field should not be empty"
#define NOT_ALPHA_ERR "Field should contain only alphabetic characters"
#define NOT_NUM_ERR "Field should contain only numeric characters"
#define INVALID_INDEX_ERR "Phone book index should be between 1 and "

typedef enum s_enum {
	DEFAULT,
	NAME,
	PHONE,
}	t_inputTypes;

#endif