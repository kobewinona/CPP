/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:24:38 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/28 20:58:46 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(){};

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << GRAY << "SubClass(FragTrap) > "
			  << CYAN << name
			  << GRAY << " is created"
			  << RESET << std::endl;

	_HP = FragTrap::_maxHP;
	_EP = FragTrap::_maxEP;
	_DMG = FragTrap::_defaultDMG;
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << GRAY << "SubClass(FragTrap) > "
			  << CYAN << getName()
			  << GRAY << " is copied"
			  << RESET << std::endl;

	_HP = other._HP;
	_EP = other._EP;
	_DMG = other._DMG;
};

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << GRAY << "SubClass(FragTrap) > "
			  << CYAN << getName()
			  << GRAY << " is assigned"
			  << RESET << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		_HP = other._HP;
		_EP = other._EP;
		_DMG = other._DMG;
	}

	return (*this);
};

// @def desctructor
FragTrap::~FragTrap(void)
{
	std::cout << GRAY << "SubClass(FragTrap) > "
			  << CYAN << getName()
			  << GRAY << " is destroyed "
			  << RESET << std::endl;
};

// @defgroup member functions
void FragTrap::highFivesGuys(void)
{
	std::cout << CYAN << getName() << RESET
			  << " sends high fives to everyone"
			  << GRAY << " (it doesn't do anything)" << RESET
			  << std::endl;
};
