/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:07:05 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/13 20:55:23 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>

int main(void)
{
  std::string string = "HI THIS IS BRAIN";
  std::string *stringPTR = &string;
  std::string &stringREF = string;

  std::cout << "The memory address of the string variable: "
            << &string << std::endl;
  std::cout << "The memory address held by stringPTR: "
            << stringPTR << std::endl;
  std::cout << "The memory address held by stringREF: "
            << &stringREF << std::endl;

  std::cout << "The value of the string variable: "
            << string << std::endl;
  std::cout << "The value pointed to by stringPTR: "
            << (*stringPTR) << std::endl;
  std::cout << "The value pointed to by stringREF: "
            << stringREF << std::endl;

  return (EXIT_SUCCESS);
};
