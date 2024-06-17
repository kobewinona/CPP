/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:26:12 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/17 11:04:59 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// @defgroup constructors
Cat::Cat() : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << GRAY << _type << " is created"
			  << RESET << std::endl;
};

Cat::Cat(const Cat &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << GRAY << _type << " is copied"
			  << RESET << std::endl;
};

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}

	std::cout << GRAY << _type << " is assigned"
			  << RESET << std::endl;

	return (*this);
};

// @def desctructor
Cat::~Cat()
{
	delete _brain;

	std::cout << GRAY << _type << " is destroyed"
			  << RESET << std::endl;
};

//@def clone constructor
Cat *Cat::clone() const
{
	return new Cat((*this));
}

// @defgroup memeber functions
void Cat::makeSound() const
{
	std::cout << _type << " says meow..." << std::endl;
};

void Cat::addIdea(std::string idea)
{
	_brain->addIdea(idea);
};

std::string Cat::getIdea(const int index) const
{
	return _brain->getIdea(index);
};

std::string Cat::getRandomIdea() const
{
	return _brain->getRandomIdea();
};
