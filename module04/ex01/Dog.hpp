/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:25:20 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 14:17:39 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;

public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	void makeSound() const;
	void addIdea(std::string idea);
	std::string getIdea(const int index) const;
	std::string getRandomIdea() const;
};

#endif
