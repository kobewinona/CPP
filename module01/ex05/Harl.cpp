/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:18 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/15 12:38:17 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){};
Harl::Harl(const Harl &other){};
Harl &Harl::operator=(const Harl &other) { return ((*this)); };
Harl::~Harl(void){};

const std::string Harl::_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
void (Harl::*const Harl::_complainFuncs[4])() = {
	&Harl::_debug,
	&Harl::_info,
	&Harl::_warning,
	&Harl::_error};

void Harl::_debug(void) { std::cout << DEBUG_MSG << std::endl; };
void Harl::_info(void) { std::cout << INFO_MSG << std::endl; };
void Harl::_warning(void) { std::cout << WARN_MSG << std::endl; };
void Harl::_error(void) { std::cout << ERR_MSG << std::endl; };

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; ++i)
	{
		if (level == _levels[i])
			return ((this->*_complainFuncs[i])());
	}

	std::cerr << INVALID_COMPLAINT_MSG << std::endl;
};
