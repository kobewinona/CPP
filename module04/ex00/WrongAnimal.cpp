/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:16:49 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 13:09:27 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

const std::string WrongAnimal::_defaultType = "unkown type";

// @defgroup constructors
WrongAnimal::WrongAnimal() : _type(_defaultType)
{
	std::cout << GRAY << "WrongAnimal of "
			  << _defaultType << " is created"
			  << RESET << std::endl;
};

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << GRAY << "WrongAnimal "
			  << type << " is created"
			  << RESET << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << GRAY << "WrongAnimal "
			  << _type << " is copied"
			  << RESET << std::endl;
};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		_type = other._type;

	std::cout << GRAY << "WrongAnimal "
			  << _type << " is assigned"
			  << RESET << std::endl;

	return (*this);
};

// @def desctructor
WrongAnimal::~WrongAnimal()
{
	std::cout << GRAY << "WrongAnimal "
			  << _type << " is destroyed"
			  << RESET << std::endl;
};

// @defgroup member functions
std::string WrongAnimal::getType() const { return _type; };

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal " << _type
			  << " `makeSound()` function is called"
			  << std::endl;
};
