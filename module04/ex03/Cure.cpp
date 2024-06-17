/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:39:32 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 15:45:28 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// @defgroup constructors
Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria(other._type) {}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);

	return (*this);
}

// @def destractor
Cure::~Cure() {}

// @def clone constructor
AMateria *Cure::clone() const
{
	return new Cure((*this));
}

// @defgroup member functions
void Cure::use(ICharacter &target)
{
	std::cout << "* heals "
			  << target.getName() << "'s wounds *"
			  << std::endl;
}
