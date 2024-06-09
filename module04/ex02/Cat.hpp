/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:25:20 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 14:18:21 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *_brain;

public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();
	AAnimal *clone() const;

	void makeSound() const;
	void addIdea(std::string idea);
	std::string getIdea(const int index) const;
	std::string getRandomIdea() const;
};

#endif
