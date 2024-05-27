/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:08:07 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/27 18:32:02 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed(void);

	// @defgroup raw value handlers
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

	// @defgroup comparison operators
	bool operator<(const Fixed &right);
	bool operator>(const Fixed &right);
	bool operator<=(const Fixed &right);
	bool operator>=(const Fixed &right);
	bool operator==(const Fixed &right);
	bool operator!=(const Fixed &right);

	// @defgroup arithmetic operators
	Fixed operator+(const Fixed &right) const;
	Fixed operator-(const Fixed &right) const;
	Fixed operator*(const Fixed &right) const;
	Fixed operator/(const Fixed &right) const;

	// @defgroup increment/decrement operators
	Fixed operator++(void);
	Fixed operator++(int);
	Fixed operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &fp1, Fixed &fp2);
	static const Fixed &min(const Fixed &fp1, const Fixed &fp2);
	static Fixed &max(Fixed &fp1, Fixed &fp2);
	static const Fixed &max(const Fixed &fp1, const Fixed &fp2);

private:
	int _fp;
	static const int _fractBits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif
