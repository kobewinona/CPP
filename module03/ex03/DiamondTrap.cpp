/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:41:29 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 11:12:13 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// @defgroup constructors
DiamondTrap::DiamondTrap(void)
	: ClapTrap(_getDefaultName() + "_clap_name"),
	  _name(_getDefaultName())
{
	std::cout << GRAY << "SubClass(DiamondTrap) > with no name provided "
			  << BLUE << _getDefaultName()
			  << GRAY << " is created"
			  << RESET << std::endl;

	_HP = FragTrap::_maxHP;
	_EP = ScavTrap::_maxEP;
	_DMG = FragTrap::_defaultDMG;
};

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),
	  _name(name)
{
	std::cout << GRAY << "SubClass(DiamondTrap) > "
			  << BLUE << name
			  << GRAY << " is created"
			  << RESET << std::endl;

	_HP = FragTrap::_maxHP;
	_EP = ScavTrap::_maxEP;
	_DMG = FragTrap::_defaultDMG;
};

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other),
	  _name(other._name)
{
	std::cout << GRAY << "SubClass(DiamondTrap) > "
			  << BLUE << other._name
			  << GRAY << " is copied"
			  << RESET << std::endl;

	_HP = other._HP;
	_EP = other._EP;
	_DMG = other._DMG;
};

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << GRAY << "SubClass(DiamondTrap) > "
			  << BLUE << other._name
			  << GRAY << " is assigned"
			  << RESET << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
		_HP = other._HP;
		_EP = other._EP;
		_DMG = other._DMG;
	}

	return (*this);
};

// @def desctructor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << GRAY << "SubClass(DiamondTrap) > "
			  << BLUE << _name
			  << GRAY << " is destroyed "
			  << RESET << std::endl;
};

// @defgroup member functions
std::string DiamondTrap::_getDefaultName(void) { return "Bruce"; };

void DiamondTrap::whoAmI(void)
{
	std::cout << BLUE << _name << ": " << RESET
			  << "\tMy DiamondTrap name is " << _name
			  << "\n\tMy ClapTrap name is " << getName()
			  << std::endl;
};
