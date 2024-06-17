/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:39:32 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 15:45:28 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// @defgroup constructors
Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other._type) {}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		AMateria::operator=(other);

	return (*this);
}

// @def destractor
Ice::~Ice() {}

// @def clone constructor
AMateria *Ice::clone() const
{
	return new Ice((*this));
}

// @defgroup member functions
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
			  << target.getName() << " *"
			  << std::endl;
}
