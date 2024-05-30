/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:07:27 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 11:11:51 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap ketchum("Ketchum");
	ClapTrap stewart("Little Stewart");
	ScavTrap willami("WillAmI");
	FragTrap dick("Dick Tracy");
	DiamondTrap lucy("Lucy");
	DiamondTrap bruce;
	bruce = lucy;
	DiamondTrap katya("Katya");

	bruce.attack(ketchum.getName());
	ketchum.takeDamage(30);
	ketchum.attack(stewart.getName());
	stewart.takeDamage(20);
	stewart.beRepaired(2);
	dick.attack(ketchum.getName());
	ketchum.takeDamage(30);
	willami.attack(stewart.getName());
	willami.takeDamage(20);
	willami.guardGate();
	willami.attack(dick.getName());
	katya.whoAmI();
	katya.getStats();
	katya.takeDamage(100);
	dick.takeDamage(20);
	dick.highFivesGuys();
	lucy.whoAmI();
	lucy.attack(ketchum.getName());
	bruce.highFivesGuys();
	lucy.guardGate();
	return (EXIT_SUCCESS);
};
