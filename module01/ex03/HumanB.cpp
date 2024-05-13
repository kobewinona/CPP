/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:46:58 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/13 20:50:56 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){};

HumanB::HumanB(const HumanB &other) : _name(other._name){};

HumanB &HumanB::operator=(const HumanB &other)
{
	if (this != &other)
	{
		_name = other._name;
		_weapon = other._weapon;
	}
	return (*this);
};

HumanB::~HumanB(void){};

void HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with no weapon" << std::endl;
};

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
};
