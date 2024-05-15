/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:32 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/15 12:42:13 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <cstdlib>
#include <iostream>
#include <string>

#define DEBUG_MSG "I love having extra bacon!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money"
#define WARN_MSG "I think I deserve to have some extra bacon for free"
#define ERR_MSG "This is unacceptable!"
#define INVALID_COMPLAINT_MSG "Invalid complaint level"

class Harl
{
public:
	Harl(void);
	Harl(const Harl &other);
	Harl &operator=(const Harl &other);
	~Harl(void);

	void complain(std::string level);

private:
	static const std::string _levels[4];
	static void (Harl::*const _complainFuncs[4])(void);

	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
};

#endif