/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:07:55 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/17 17:29:51 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor is called" << std::endl;
};

Fixed::Fixed(const int num) : _fixedPointValue(num << _fractionalBits)
{
	std::cout << "Int constructor is called" << std::endl;
};

Fixed::Fixed(const float num) : _fixedPointValue(num * (1 << _fractionalBits))
{
	std::cout << "Float constructor is called" << std::endl;
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

int Fixed::getRawBits(void) const { return _fixedPointValue; };
void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; };

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
};

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	return os << obj.toFloat();
};
