/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:15:48 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 13:41:09 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

void makeAnimaltoMakeSound(const Animal &animal)
{
	std::cout << GRAY << "from `makeAnimaltoMakeSound`:\t" << RESET;
	animal.makeSound();
};

int main(void)
{
	const Animal *animal = new Animal();
	const Animal *bob = new Dog();
	const Animal *felix = new Cat();

	std::cout << bob->getType() << " " << std::endl;
	std::cout << felix->getType() << " " << std::endl;
	bob->makeSound();
	felix->makeSound();
	animal->makeSound();
	makeAnimaltoMakeSound(*felix);

	delete animal;
	delete bob;
	delete felix;

	std::cout << RED << "\n--- wrong cat and animal ---"
			  << RESET << std::endl;
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongFelix = new WrongCat();

	std::cout << wrongFelix->getType() << " " << std::endl;
	wrongFelix->makeSound();
	wrongAnimal->makeSound();

	delete wrongAnimal;
	delete wrongFelix;

	std::cout << RED << "\n--- virtual desctructor ---"
			  << RESET << std::endl;
	Animal *anotherAnimal = new Cat();
	delete anotherAnimal;

	return EXIT_SUCCESS;
};
