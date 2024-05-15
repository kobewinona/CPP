/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:32 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/15 14:31:50 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <cstdlib>
#include <iostream>
#include <string>

// @info log levels
#define DEBUG_LVL "DEBUG"
#define INFO_LVL "INFO"
#define WARNING_LVL "WARNING"
#define ERROR_LVL "ERROR"

// @info log levels messages
#define DEBUG_MSG "I love having extra bacon!\n"
#define INFO_MSG "I cannot believe adding extra bacon costs more money\n"
#define WARN_MSG "I think I deserve to have some extra bacon for free\n"
#define ERR_MSG "This is unacceptable!\n"
#define DEAFAULT_MSG "Probably complaining about insignificant problems"

class Harl
{
public:
	Harl(void);
	Harl(const Harl &other);
	Harl &operator=(const Harl &other);
	~Harl(void);

	void complain(std::string logLevel);

private:
	enum _logLevelID
	{
		INVALID,
		DEBUG,
		INFO,
		WARNING,
		ERROR,
	};

	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
	void _printLogLevelHeader(std::string logLevel);
	_logLevelID _resolveLogLevel(std::string logLevel);
};

#endif