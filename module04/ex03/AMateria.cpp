/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:39:32 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 18:47:58 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// @defgroup constructors
AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		_type = other._type;

	return (*this);
}

// @def destractor
AMateria::~AMateria() {}

// @defgroup member functions
std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target)
{
	std::cout << "* " << _type
			  << "is used on " << target.getName() << " *"
			  << std::endl;
}
