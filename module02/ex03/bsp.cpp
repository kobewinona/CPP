/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:50:25 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/27 18:52:33 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int getAreaSign(Point const p1, Point const p2, Point const p3)
{
	Fixed signedArea = ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
						(p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));

	if (signedArea > 0)
		return 1;
	if (signedArea < 0)
		return -1;
	return 0;
};

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	int d1 = getAreaSign(point, a, b);
	int d2 = getAreaSign(point, b, c);
	int d3 = getAreaSign(point, c, a);
	bool isLeftSide = false, isRightSide = false;

	isLeftSide = d1 < 0 && d2 < 0 && d3 < 0;
	isRightSide = d1 > 0 && d2 > 0 && d3 > 0;

	return (isLeftSide || isRightSide);
};