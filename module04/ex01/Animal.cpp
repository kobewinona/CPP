/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:16:49 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 13:09:27 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

const std::string Animal::_defaultType = "unkown type";

// @defgroup constructors
Animal::Animal() : _type(_defaultType)
{
	std::cout << GRAY << "Animal of "
			  << _defaultType << " is created"
			  << RESET << std::endl;
};

Animal::Animal(std::string type) : _type(type)
{
	std::cout << GRAY << "Animal "
			  << type << " is created"
			  << RESET << std::endl;
};

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << GRAY << "Animal "
			  << _type << " is copied"
			  << RESET << std::endl;
};

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other._type;

	std::cout << GRAY << "Animal "
			  << _type << " is assigned"
			  << RESET << std::endl;

	return (*this);
};

// @def desctructor
Animal::~Animal()
{
	std::cout << GRAY << "Animal "
			  << _type << " is destroyed"
			  << RESET << std::endl;
};

// @defgroup member functions
std::string Animal::getType() const { return _type; };

void Animal::makeSound() const
{
	std::cout << "Animal " << _type
			  << " `makeSound()` function is called"
			  << std::endl;
};
