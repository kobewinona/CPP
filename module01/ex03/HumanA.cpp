/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:46:26 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/17 15:52:10 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){};

HumanA::HumanA(const HumanA &other) : _name(other._name), _weapon(other._weapon){};

HumanA &HumanA::operator=(const HumanA &other)
{
	if (this != &other)
	{
		_name = other._name;
		_weapon = other._weapon;
	}
	return (*this);
};

HumanA::~HumanA(void){};

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
};
