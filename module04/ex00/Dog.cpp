/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:26:12 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 12:54:24 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// @defgroup constructors
Dog::Dog() : Animal("Dog")
{
	std::cout << GRAY << _type << " is created"
			  << RESET << std::endl;
};

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << GRAY << _type << " is copied"
			  << RESET << std::endl;
};

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		Animal::operator=(other);

	std::cout << GRAY << _type << " is assigned"
			  << RESET << std::endl;

	return (*this);
};

// @def desctructor
Dog::~Dog()
{
	std::cout << GRAY << _type << " is destroyed"
			  << RESET << std::endl;
};

// @defgroup memeber functions
void Dog::makeSound() const
{
	std::cout << _type << " says wuff!" << std::endl;
};
