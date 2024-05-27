/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:25:53 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/27 19:53:00 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){};
Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y)){};
Point::Point(const Point &other) : _x(other._x), _y(other._y){};
Point &Point::operator=(const Point &other)
{
	(void)&other;
	return (*this);
};
Point::~Point(void){};

Fixed Point::getX(void) const { return _x; };
Fixed Point::getY(void) const { return _y; };
