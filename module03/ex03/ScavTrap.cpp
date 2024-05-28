/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:44:07 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/28 20:58:09 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// @defgroup constructors
ScavTrap::ScavTrap(void) : ClapTrap(){};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << GRAY << "SubClass(ScavTrap) > "
			  << PURPLE << name
			  << GRAY << " is created"
			  << RESET << std::endl;

	_HP = ScavTrap::_maxHP;
	_EP = ScavTrap::_maxEP;
	_DMG = ScavTrap::_defaultDMG;
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << GRAY << "SubClass(ScavTrap) > "
			  << PURPLE << getName()
			  << GRAY << " is copied"
			  << RESET << std::endl;

	_HP = other._HP;
	_EP = other._EP;
	_DMG = other._DMG;
};

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << GRAY << "SubClass(ScavTrap) > "
			  << PURPLE << getName()
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
ScavTrap::~ScavTrap(void)
{
	std::cout << GRAY << "SubClass(ScavTrap) > "
			  << PURPLE << getName()
			  << GRAY << " is destroyed "
			  << RESET << std::endl;
};

// @defgroup member functions
void ScavTrap::attack(const std::string &target)
{
	std::cout << PURPLE << getName() << RESET;

	if (_EP == 0)
	{
		std::cout << " is out of energy points, cannot attack"
				  << std::endl;
	}
	else
	{
		_EP -= 1;

		std::cout << " demolishes " << target << " causing "
				  << BALD_WHITE << _DMG << RESET
				  << " points of damage!"
				  << std::endl;
	}
};

void ScavTrap::guardGate(void)
{
	std::cout << PURPLE << getName() << RESET
			  << " is now in Gate Keeper mode"
			  << std::endl;
};
