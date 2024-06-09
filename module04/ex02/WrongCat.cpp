/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:26:12 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 12:56:34 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// @defgroup constructors
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << GRAY << _type << " is created"
			  << RESET << std::endl;
};

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << GRAY << _type << " is copied"
			  << RESET << std::endl;
};

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);

	std::cout << GRAY << _type << " is assigned"
			  << RESET << std::endl;

	return (*this);
};

// @def desctructor
WrongCat::~WrongCat()
{
	std::cout << GRAY << _type << " is destroyed"
			  << RESET << std::endl;
};

// @defgroup memeber functions
void WrongCat::makeSound() const
{
	std::cout << _type << " says meow..." << std::endl;
};
