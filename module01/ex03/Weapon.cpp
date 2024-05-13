/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:45:04 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/13 20:16:17 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void){};

Weapon::Weapon(std::string type) : _type(type){};

Weapon::Weapon(const Weapon &other) : _type(other._type){};

Weapon &Weapon::operator=(const Weapon &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
};

Weapon::~Weapon(void){};

const std::string &Weapon::getType(void) const
{
	return _type;
};

void Weapon::setType(std::string type)
{
	_type = type;
};
