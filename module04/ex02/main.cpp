/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:15:48 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/17 11:06:31 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void makeAnimaltoMakeSound(const AAnimal &AAnimal)
{
	std::cout << GRAY << "from `makeAnimaltoMakeSound`:\t" << RESET;
	AAnimal.makeSound();
};

int main(void)
{
	std::cout << "-- tests for brain deep cpying with brain --" << std::endl;

	std::srand(std::time(0));

	AAnimal *beethoven = new Dog();
	std::cout << "Beethoven's random idea: " << beethoven->getRandomIdea() << std::endl;

	Cat *felix = new Cat();
	felix->addIdea("to eat");
	std::cout << "Felix's idea #0: " << felix->getIdea(0) << std::endl;
	felix->addIdea("to think deeply about life");
	std::cout << "Felix's idea #1: " << felix->getIdea(1) << std::endl;

	// doesn't work anymore because Animal is now an abstract class
	// and can only be used as a prototype to create derived classes
	// AAnimal tom(*felix);
	// this works instead because we explicitly create a Cat instance, not Animal instance
	AAnimal *tom = new Cat();
	*tom = *felix;
	std::cout << "Tom's idea #0: " << tom->getIdea(0) << std::endl;

	AAnimal *scratchy = felix->clone();
	std::cout << "Scratchy's idea #0: " << scratchy->getIdea(0) << std::endl;

	Cat newCat;
	std::cout << "newCat's idea #0: " << newCat.getIdea(0) << std::endl;

	delete felix;
	delete tom;
	delete scratchy;
	delete beethoven;

	// std::cout << "-- tests for AAnimal array --" << std::endl;

	// int animalsCount = 100;

	// AAnimal *animals[animalsCount];

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
