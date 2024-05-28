/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:02:38 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/28 18:21:09 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RESET "\033[0m"
#define GRAY "\033[90m"
#define RED "\033[31m"
#define BALD_WHITE "\33[1;1m"

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap(void);

	void setName(std::string name);
	std::string getName(void);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string _name;

	static const unsigned int _maxHP = 10;
	static const unsigned int _maxEP = 10;
	static const unsigned int _defaultDMG = 0;

protected:
	unsigned int _HP;
	unsigned int _EP;
	unsigned int _DMG;
};

#endif
