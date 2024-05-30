/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:07:27 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 16:51:54 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("John");
	ClapTrap b("Doe");
	ClapTrap c;

	a.attack(b.getName());
	b.takeDamage(20);
	b.beRepaired(2);
	c.attack(a.getName());

	return EXIT_SUCCESS;
};
