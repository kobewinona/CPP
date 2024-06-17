/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:36:49 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/17 13:04:41 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define FLOOR_CAPACITY 100

void addToFloor(AMateria *floor[FLOOR_CAPACITY], AMateria *m)
{
	for (int i = 0; i < FLOOR_CAPACITY; ++i)
	{
		if (!floor[i])
		{
			floor[i] = m;
			return;
		}
	}
}

void clearFloor(AMateria *floor[FLOOR_CAPACITY])
{
	for (int i = 0; i < FLOOR_CAPACITY; ++i)
	{
		if (floor[i])
			delete floor[i];
	}
}

int main()
{
	// for storing unequpped materia
	AMateria *floor[FLOOR_CAPACITY] = {NULL};

	IMateriaSource *src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	ICharacter *notMe = new Character("not me");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	// deep copying testing
	tmp = src->createMateria("cure");
	notMe->equip(tmp);
	notMe->use(0, *me);
	*static_cast<Character *>(notMe) = *static_cast<Character *>(me);
	notMe->use(0, *me);
	Character notMe2(*static_cast<Character *>(me));
	notMe2.use(0, *notMe);

	tmp = src->createMateria("cure");
	me->equip(tmp);
	// me->equip(tmp);
	// me->equip(tmp);
	// me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	// me->use(2, *bob);
	addToFloor(floor, me->getMateria(0));
	me->unequip(0);
	me->use(0, *bob);

	delete bob;
	delete me;
	delete notMe;
	delete src;
	clearFloor(floor);

	return EXIT_SUCCESS;
}
