/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:07:27 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/27 18:55:35 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Point.hpp"

#define IN "is inside of the given triangle"
#define OUT "is outside, on the vertex or on the edge of the given triangle"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 3);

	std::cout << "given triangle: A("
			  << a.getX() << "," << a.getY() << ")"
			  << ", B("
			  << b.getX() << "," << b.getY() << ")"
			  << ", C("
			  << c.getX() << "," << c.getY() << ")\n"
			  << std::endl;

	Point point1(1, 1);
	std::cout << "P1(1,1) " << ((bsp(a, b, c, point1) == true) ? IN : OUT) << std::endl;

	Point point2(2, 3);
	std::cout << "P2(2,3) " << ((bsp(a, b, c, point2) == true) ? IN : OUT) << std::endl;

	Point point3(5, 5);
	std::cout << "P3(5,5) " << ((bsp(a, b, c, point3) == true) ? IN : OUT) << std::endl;

	return (EXIT_SUCCESS);
};
