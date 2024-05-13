/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:05:26 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/13 18:29:48 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class Zombie
{
public:
	Zombie(std::string name);
	Zombie(const Zombie &other);
	Zombie &operator=(const Zombie &other);
	~Zombie(void);

	void announce(void);

private:
	std::string _name;
};

Zombie *
newZombie(std::string name);
void randomChump(std::string name);

#endif
