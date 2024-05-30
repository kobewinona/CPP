/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:15:48 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 20:01:18 by dklimkin         ###   ########.fr       */
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
	std::srand(std::time(0));

	Animal *felix = new Cat();
	Animal *bethoven = new Dog();

	felix->addIdea("to eat");
	std::cout << "Felix's idea #18: " << felix->getIdea(18) << std::endl;
	Animal tom(*felix);
	Animal *scratchy;
	std::cout << "Tom's idea #18: " << felix->getIdea(18) << std::endl;
	scratchy = felix;
	std::cout << "Scratchy's idea #18: " << scratchy->getIdea(18) << std::endl;

	std::cout << "Felix's random idea: " << bethoven->getRandomIdea() << std::endl;

	delete felix;
	delete bethoven;

	return EXIT_SUCCESS;
};
