/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:39:32 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 15:45:28 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// @defgroup constructors
Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < _maxInventory; ++i)
		_inventory[i] = NULL;
};

Character::Character(const Character &other) : _name(other._name)
{
	for (int i = 0; i < _maxInventory; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
};

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;

		for (int i = 0; i < _maxInventory; ++i)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}

			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}

	return (*this);
};

// @def destractor
Character::~Character()
{
	for (int i = 0; i < _maxInventory; ++i)
		delete _inventory[i];
};

// @defgroup getters/setters
AMateria *Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < _maxInventory)
		return _inventory[idx];
	return NULL;
}

std::string const &Character::getName() const { return _name; };

// @defgroup member functions
void Character::equip(AMateria *m)
{
	int i = 0;

	while (_inventory[i])
	{
		if (_inventory[i] == m)
		{
			std::cout << "materia `" << m->getType()
					  << "` is already equipped" << std::endl;
			return;
		}
		i++;
	}

	if (i < _maxInventory)
		_inventory[i] = m;
	else
		std::cout << "inventory is full" << std::endl;
};

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < _maxInventory)
		_inventory[idx] = NULL;
};

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < _maxInventory && _inventory[idx])
		_inventory[idx]->use(target);
};
