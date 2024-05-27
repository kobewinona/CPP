/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:25:53 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/27 17:59:25 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){};
Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y)){};
Point::Point(const Point &other) : _x(other._x), _y(other._y){};
Point &Point::operator=(const Point &other) { return (*this); };
Point::~Point(void){};

Fixed Point::getX(void) const { return _x; };
Fixed Point::getY(void) const { return _y; };

int Point::_getAreaSign(Point const p1, Point const p2, Point const p3)
{
	Fixed signedArea = ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));

	if (signedArea > 0)
		return 1;
	if (signedArea < 0)
		return -1;
	return 0;
};

const bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	int d1 = _getAreaSign(point, a, b);
	int d2 = _getAreaSign(point, b, c);
	int d3 = _getAreaSign(point, c, a);
	bool isLeftSide = false, isRightSide = false;

	isLeftSide = d1 < 0 && d2 < 0 && d3 < 0;
	isRightSide = d1 > 0 && d2 > 0 && d3 > 0;

	return (isLeftSide || isRightSide);
};
