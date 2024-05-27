/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:44:07 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/27 22:15:04 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: ClapTrap()
{
	std::cout << "> ScavTrap default constractor is called with no name provided" << std::endl;

	_hitPoints = ST_MAX_HP;
	_energyPoints = ST_MAX_EP;
	_attackDamage = ST_DMG;
};

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "> ScavTrap default constractor is called" << std::endl;

	_hitPoints = ST_MAX_HP;
	_energyPoints = ST_MAX_EP;
	_attackDamage = ST_DMG;
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "> ScavTrap copy constractor is called" << std::endl;

	(*this) = other;
};

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "> ScavTrap assign constractor is called" << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);

	return (*this);
};

ScavTrap::~ScavTrap(void)
{
	std::cout << "> ScavTrap destructor is called" << std::endl;
};

void ScavTrap::guardGate(void)
{
	std::cout << getName() << " is now in Gate keeper mode" << std::endl;
};
