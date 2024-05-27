/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:02:31 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/27 22:14:21 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("Chuck"),
	  _hitPoints(CT_MAX_HP),
	  _energyPoints(CT_MAX_EP),
	  _attackDamage(CT_DMG)
{
	std::cout << "> ClapTrap default constractor is called with no name provided" << std::endl;
};
ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _hitPoints(CT_MAX_HP),
	  _energyPoints(CT_MAX_EP),
	  _attackDamage(CT_DMG)
{
	std::cout << "> ClapTrap default constractor is called" << std::endl;
};
ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name)
{
	std::cout << "> ClapTrap copy constractor is called" << std::endl;
};
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "> ClapTrap assign constractor is called" << std::endl;

	if (this != &other)
		_name = other._name;

	return (*this);
};
ClapTrap::~ClapTrap(void)
{
	std::cout << "> ClapTrap destructor is called" << std::endl;
};

void ClapTrap::setName(std::string name) { _name = name; };
std::string ClapTrap::getName(void) { return _name; };

void ClapTrap::attack(const std::string &target)
{
	_energyPoints -= 1;

	std::cout << _name << " attacks " << target
			  << " causing " << _attackDamage << " points of damage!"
			  << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount)
{
	int newHitPoints = (_hitPoints - amount);
	_hitPoints = newHitPoints < 0 ? 0 : newHitPoints;

	std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
};
void ClapTrap::beRepaired(unsigned int amount)
{
	_energyPoints -= 1;
	_hitPoints += amount;

	std::cout << _name << " repairs itself for " << amount << " hit points!" << std::endl;
};
