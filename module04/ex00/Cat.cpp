/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:26:12 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 12:56:34 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// @defgroup constructors
Cat::Cat() : Animal("Cat")
{
	std::cout << GRAY << _type << " is created"
			  << RESET << std::endl;
};

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << GRAY << _type << " is copied"
			  << RESET << std::endl;
};

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);

	std::cout << GRAY << _type << " is assigned"
			  << RESET << std::endl;

	return (*this);
};

// @def desctructor
Cat::~Cat()
{
	std::cout << GRAY << _type << " is destroyed"
			  << RESET << std::endl;
};

// @defgroup memeber functions
void Cat::makeSound() const
{
	std::cout << _type << " says meow..." << std::endl;
};
