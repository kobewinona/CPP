/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:07:05 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/13 17:53:34 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
  if (argc != 2)
    return (EXIT_FAILURE);

  int n = std::atoi(argv[1]);
  Zombie *horde = zombieHorde(n, "Chuck");

  for (int i = 0; i < n; ++i)
    horde[i].announce();

  return (delete[] horde, EXIT_SUCCESS);
};
