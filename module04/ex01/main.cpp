/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:15:48 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 14:30:19 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void makeAnimaltoMakeSound(const Animal &animal)
{
	std::cout << GRAY << "from `makeAnimaltoMakeSound`:\t" << RESET;
	animal.makeSound();
};

int main(void)
{
	Brain brain;

	for (int i = 0; i < 105; ++i)
	{
		brain.addIdea("idea" << i);
	}

	brain.getRandomIdea();

	return EXIT_SUCCESS;
};
