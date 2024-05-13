/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:05:26 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/13 18:29:41 by dklimkin         ###   ########.fr       */
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
  Zombie(void);
  Zombie(const Zombie &other);
  Zombie &operator=(const Zombie &other);
  ~Zombie(void);

  void announce(void);
  void setName(std::string name);

private:
  std::string _name;
};

Zombie *
zombieHorde(int n, std::string name);

#endif
