/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:02:31 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/28 21:05:01 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// @defgroup constructors
ClapTrap::ClapTrap(void)
	: _name("Chuck"), _HP(_maxHP), _EP(_maxEP), _DMG(_defaultDMG)
{
	std::cout << GRAY << "ClapTrap > with no name provided "
			  << RED << _name
			  << GRAY << " is created"
			  << RESET << std::endl;
};

ClapTrap::ClapTrap(std::string name)
	: _name(name), _HP(_maxHP), _EP(_maxEP), _DMG(_defaultDMG)
{
	std::cout << GRAY << "ClapTrap > "
			  << RED << name
			  << GRAY << " is created"
			  << RESET << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name)
{
	std::cout << GRAY << "ClapTrap > "
			  << RED << other._name
			  << GRAY << " is copied"
			  << RESET << std::endl;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << GRAY << "ClapTrap > "
			  << RED << other._name
			  << GRAY << " is assigned"
			  << RESET << std::endl;

	if (this != &other)
		_name = other._name;

	return (*this);
};

// @def desctructor
ClapTrap::~ClapTrap(void)
{
	std::cout << GRAY << "ClapTrap > "
			  << RED << _name
			  << GRAY << " is destroyed "
			  << RESET << std::endl;
};

// @defgroup getters, setters
void ClapTrap::setName(std::string name) { _name = name; };
std::string ClapTrap::getName(void) { return _name; };

// @defgroup member functions
void ClapTrap::attack(const std::string &target)
{
	std::cout << RED << _name << RESET;

	if (_EP == 0)
	{
		std::cout << " is out of energy points, cannot attack"
				  << std::endl;
	}
	else if (_HP == 0)
		std::cout << " is dead, cannot attack" << std::endl;
	else
	{
		_EP -= 1;

		std::cout << " attacks " << target << " causing "
				  << BALD_WHITE << _DMG << RESET
				  << " points of damage!"
				  << std::endl;
	}
};

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HP == 0)
	{
		std::cout << RED << _name << RESET
				  << " is already dead, cannot take damage"
				  << std::endl;
		return;
	}

	int takenDamage = amount > _HP ? _HP : amount;
	_HP = amount > _HP ? 0 : (_HP - amount);

	std::cout << RED << _name << RESET
			  << " takes "
			  << BALD_WHITE << takenDamage << RESET
			  << " points of damage!"
			  << std::endl;

	std::cout << RED << _name << "'s" << RESET
			  << " HP after being hit is "
			  << BALD_WHITE << _HP << RESET
			  << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << RED << _name << RESET;

	if (_EP == 0)
	{
		std::cout << " is out of energy points, cannot repair"
				  << std::endl;
	}
	else if (_HP == 0)
		std::cout << " is dead, cannot repair" << std::endl;
	else
	{
		_EP -= 1;

		unsigned int newHitPoints = (_HP + amount);
		_HP = newHitPoints > _maxHP ? _maxHP : newHitPoints;

		std::cout << " repairs itself for "
				  << BALD_WHITE << amount << RESET
				  << " hit points!"
				  << std::endl;

		std::cout << RED << _name << "'s" << RESET
				  << " HP after repair is "
				  << BALD_WHITE << _HP << RESET
				  << std::endl;
	}
};
