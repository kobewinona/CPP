/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:07:27 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/27 22:15:16 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("John");
	ClapTrap b("Doe");
	ClapTrap c;
	ScavTrap d("Shiny");

	a.attack(b.getName());
	b.takeDamage(20);
	b.beRepaired(2);
	c.attack(a.getName());
	d.attack(b.getName());
	d.takeDamage(20);
	d.guardGate();
	return (EXIT_SUCCESS);
};
