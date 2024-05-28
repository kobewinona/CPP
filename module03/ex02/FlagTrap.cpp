/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:24:38 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/28 13:30:42 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void)
	: ClapTrap()
{
	std::cout << "> FlagTrap default constractor is called with no name provided" << std::endl;

	_hitPoints = FT_MAX_HP;
	_energyPoints = FT_MAX_EP;
	_attackDamage = FT_DMG;
};

FlagTrap::FlagTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "> FlagTrap default constractor is called" << std::endl;

	_hitPoints = FT_MAX_HP;
	_energyPoints = FT_MAX_EP;
	_attackDamage = FT_DMG;
};

FlagTrap::FlagTrap(const FlagTrap &other) : ClapTrap(other)
{
	std::cout << "> FlagTrap copy constractor is called" << std::endl;

	(*this) = other;
};

FlagTrap &FlagTrap::operator=(const FlagTrap &other)
{
	std::cout << "> FlagTrap assign constractor is called" << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);

	return (*this);
};

FlagTrap::~FlagTrap(void)
{
	std::cout << "> FlagTrap destructor is called" << std::endl;
};

void FlagTrap::highFivesGuys(void)
{
	std::cout << getName() << " says high fives guys!" << std::endl;
};
