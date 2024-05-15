/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:18 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/15 14:32:03 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){};
Harl::Harl(const Harl &){};
Harl &Harl::operator=(const Harl &) { return ((*this)); };
Harl::~Harl(void){};

void Harl::_debug(void) { std::cout << DEBUG_MSG << std::endl; };
void Harl::_info(void) { std::cout << INFO_MSG << std::endl; };
void Harl::_warning(void) { std::cout << WARN_MSG << std::endl; };
void Harl::_error(void) { std::cout << ERR_MSG << std::endl; };

Harl::_logLevelID Harl::_resolveLogLevel(std::string logLevel)
{
	if (logLevel.compare(DEBUG_LVL) == 0)
		return (DEBUG);
	else if (logLevel.compare(INFO_LVL) == 0)
		return (INFO);
	else if (logLevel.compare(WARNING_LVL) == 0)
		return (WARNING);
	else if (logLevel.compare(ERROR_LVL) == 0)
		return (ERROR);
	return (INVALID);
};

void Harl::_printLogLevelHeader(std::string logLevel)
{
	std::cout << "[ " << logLevel << " ]" << std::endl;
};

void Harl::complain(std::string logLevel)
{
	switch (_resolveLogLevel(logLevel))
	{
	case DEBUG:
		_printLogLevelHeader(DEBUG_LVL);
		_debug();
	case INFO:
		_printLogLevelHeader(INFO_LVL);
		_info();
	case WARNING:
		_printLogLevelHeader(WARNING_LVL);
		_warning();
	case ERROR:
		_printLogLevelHeader(ERROR_LVL);
		_error();
		break;

	default:
		_printLogLevelHeader(DEAFAULT_MSG);
		break;
	}
};
