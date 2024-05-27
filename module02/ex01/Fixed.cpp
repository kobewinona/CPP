/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:07:55 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/27 19:49:51 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fp(0)
{
	std::cout << "Default constructor is called" << std::endl;
};

Fixed::Fixed(const int num) : _fp(num << _fractBits)
{
	std::cout << "Int constructor is called" << std::endl;
};

Fixed::Fixed(const float num) : _fp(roundf(num * (1 << _fractBits)))
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
		_fp = other.getRawBits();
	return (*this);
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
};

const int Fixed::_fractBits = 8;

int Fixed::getRawBits(void) const { return _fp; };
void Fixed::setRawBits(int const raw) { _fp = raw; };
int Fixed::toInt(void) const { return _fp >> _fractBits; };
float Fixed::toFloat(void) const { return static_cast<float>(_fp) / (1 << _fractBits); };

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	return os << obj.toFloat();
};
