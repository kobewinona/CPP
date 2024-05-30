/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:07:27 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 16:51:44 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap john("John");
	ClapTrap doe("Doe");
	ScavTrap shiny("Shiny");
	FragTrap charlie("Charlie");

	john.attack(doe.getName());
	doe.takeDamage(20);
	doe.beRepaired(2);
	charlie.attack(john.getName());
	john.takeDamage(30);
	shiny.attack(doe.getName());
	shiny.takeDamage(20);
	shiny.guardGate();
	shiny.attack(charlie.getName());
	charlie.takeDamage(20);
	charlie.highFivesGuys();

	return EXIT_SUCCESS;
};
