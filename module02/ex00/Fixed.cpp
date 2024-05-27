/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:07:55 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/17 17:29:55 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;

	setRawBits(other.getRawBits());
};

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return (*this);
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
};

const int Fixed::_fractionalBits = 8;

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return _fixedPointValue;
};

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	_fixedPointValue = raw;
};
