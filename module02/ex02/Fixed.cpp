/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:07:55 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/18 21:56:38 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// @defgroup constructors
Fixed::Fixed(void) : _fp(0){};
Fixed::Fixed(const int num) : _fp(num << _fractBits){};
Fixed::Fixed(const float num) : _fp(num * (1 << _fractBits)){};
Fixed::Fixed(const Fixed &other) { setRawBits(other._fp); };
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_fp = other._fp;
	return (*this);
};
Fixed::~Fixed(void){};

// @defgroup static values
const int Fixed::_fractBits = 8;

// @defgroup raw value handlers
int Fixed::getRawBits(void) const { return _fp; };
void Fixed::setRawBits(int const raw) { _fp = raw; };
int Fixed::toInt(void) const { return _fp >> _fractBits; };
float Fixed::toFloat(void) const { return static_cast<float>(_fp) / (1 << _fractBits); };

// @defgroup comparison operators
bool Fixed::operator<(const Fixed &right) { return _fp < right._fp; };
bool Fixed::operator>(const Fixed &right) { return _fp > right._fp; };
bool Fixed::operator<=(const Fixed &right) { return _fp <= right._fp; };
bool Fixed::operator>=(const Fixed &right) { return _fp >= right._fp; };
bool Fixed::operator==(const Fixed &right) { return _fp == right._fp; };
bool Fixed::operator!=(const Fixed &right) { return _fp != right._fp; };

// @defgroup arithmetic operators
Fixed Fixed::operator+(const Fixed &right) const
{
	return Fixed((_fp + right._fp) >> _fractBits);
};

Fixed Fixed::operator-(const Fixed &right) const
{
	return Fixed((_fp - right._fp) >> _fractBits);
};

Fixed Fixed::operator*(const Fixed &right) const
{
	return Fixed(toFloat() * right.toFloat());
};

Fixed Fixed::operator/(const Fixed &right) const
{
	return Fixed(toFloat() / right.toFloat());
};

// @defgroup increment/decrement operators
Fixed Fixed::operator++(void)
{
	_fp += 1;
	return (*this);
};

Fixed Fixed::operator++(int)
{
	Fixed temp((*this));
	_fp += 1;
	return temp;
};

Fixed Fixed::operator--(void)
{
	_fp -= 1;
	return (*this);
};

Fixed Fixed::operator--(int)
{
	Fixed temp((*this));
	_fp -= 1;
	return temp;
};

// @defgroup min/max
Fixed &Fixed::min(Fixed &fp1, Fixed &fp2)
{
	return (fp1._fp < fp2._fp) ? fp1 : fp2;
};

const Fixed &Fixed::min(const Fixed &fp1, const Fixed &fp2)
{
	return (fp1._fp < fp2._fp ? fp1 : fp2);
};

Fixed &Fixed::max(Fixed &fp1, Fixed &fp2)
{
	return (fp1._fp > fp2._fp ? fp1 : fp2);
};

const Fixed &Fixed::max(const Fixed &fp1, const Fixed &fp2)
{
	return (fp1._fp > fp2._fp ? fp1 : fp2);
};

// @defgroup stream operator
std::ostream &
operator<<(std::ostream &os, const Fixed &obj)
{
	return os << obj.toFloat();
};
