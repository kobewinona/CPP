/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:44:55 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/13 19:37:15 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon(void);
	Weapon(std::string type);
	Weapon(const Weapon &other);
	Weapon &operator=(const Weapon &other);
	~Weapon(void);

	const std::string &getType(void) const;
	void setType(std::string type);

private:
	std::string _type;
};

#endif
