/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:10:54 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/13 17:53:36 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Chuck"){};

Zombie::Zombie(const Zombie &other) : _name(other._name){};

Zombie &Zombie::operator=(const Zombie &other)
{
  if (this != &other)
    _name = other._name;
  return (*this);
};

Zombie::~Zombie() { std::cout << _name << " is destroyed" << std::endl; };

void Zombie::setName(std::string name) { _name = name; };

void Zombie::announce(void)
{
  std::cout << _name << ": "
            << "BraiiiiiiinnnzzzZ..." << std::endl;
};
