/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:47:06 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/13 20:15:02 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	HumanB(const HumanB &other);
	HumanB &operator=(const HumanB &other);
	~HumanB(void);

	void attack(void);
	void setWeapon(Weapon &weapon);

private:
	std::string _name;
	Weapon *_weapon;
};

#endif