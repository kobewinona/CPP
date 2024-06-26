/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:15:48 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 15:07:54 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
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
	std::cout << "-- tests for brain deep cpying with brain --" << std::endl;

	std::srand(std::time(0));

	Animal *beethoven = new Dog();
	std::cout << "Felix's random idea: " << beethoven->getRandomIdea() << std::endl;

	Animal *felix = new Cat();
	felix->addIdea("to eat");
	std::cout << "Felix's idea #0: " << felix->getIdea(0) << std::endl;
	felix->addIdea("to think deeply about life");
	std::cout << "Felix's idea #1: " << felix->getIdea(1) << std::endl;

	Animal tom(*felix);
	std::cout << "Tom's idea #0: " << tom.getIdea(0) << std::endl;

	Cat *scratchy = new Cat();
	*scratchy = *static_cast<Cat *>(felix);
	std::cout << "Scratchy's idea #0: " << scratchy->getIdea(0) << std::endl;

	Cat newCat;
	std::cout << "newCat's idea #0: " << newCat.getIdea(0) << std::endl;

	delete felix;
	delete scratchy;
	delete beethoven;

	// std::cout << "-- tests for Animal array --" << std::endl;

	// int animalsCount = 100;

	// Animal *animals[animalsCount];

	// for (int i = 0; i < animalsCount; ++i)
	// {
	// 	std::cout << "i " << i << " ";
	// 	if (i < (animalsCount / 2))
	// 		animals[i] = new Cat();
	// 	else
	// 		animals[i] = new Dog();
	// }

	// for (int i = 0; i < animalsCount; ++i)
	// {
	// 	std::cout << "i " << i << " ";
	// 	delete animals[i];
	// }

	return EXIT_SUCCESS;
};
