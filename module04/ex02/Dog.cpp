/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:26:12 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 14:30:29 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// @defgroup constructors
Dog::Dog() : AAnimal("Dog"), _brain(new Brain())
{
	std::cout << GRAY << _type << " is created"
			  << RESET << std::endl;
};

Dog::Dog(const Dog &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << GRAY << _type << " is copied"
			  << RESET << std::endl;
};

Dog &Dog::operator=(const Dog &other)
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
Dog::~Dog()
{
	delete _brain;

	std::cout << GRAY << _type << " is destroyed"
			  << RESET << std::endl;
};

//@def clone constructor
AAnimal *Dog::clone() const
{
	return new Dog((*this));
}

// @defgroup memeber functions
void Dog::makeSound() const
{
	std::cout << _type << " says wuff!" << std::endl;
};

void Dog::addIdea(std::string idea)
{
	_brain->addIdea(idea);
};

std::string Dog::getIdea(const int index) const
{
	return _brain->getIdea(index);
};

std::string Dog::getRandomIdea() const
{
	return _brain->getRandomIdea();
};
