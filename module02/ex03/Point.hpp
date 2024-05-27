/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:26:14 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/27 18:54:08 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(float x, float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point(void);

	Fixed getX(void) const;
	Fixed getY(void) const;

private:
	Fixed const _x;
	Fixed const _y;
};

#endif
