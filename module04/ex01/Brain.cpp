/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:11:03 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 14:24:46 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// @defgroup destractor
Brain::Brain()
{
	for (int i = 0; i < 100; ++i)
		_ideas[i] = "";

	std::cout << "Brain is created" << std::endl;
};

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < _maxIdeas; ++i)
		_ideas[i] = other._ideas[i];

	std::cout << "Brain is copied" << std::endl;
};

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < _maxIdeas; ++i)
			_ideas[i] = other._ideas[i];
	}

	std::cout << "Brain is assigned" << std::endl;

	return (*this);
};

// @def destractor
Brain::~Brain()
{
	std::cout << "Brain is destroyed" << std::endl;
};

// @defgroup memeber functions
void Brain::addIdea(std::string idea)
{
	for (int i = 0; i < _maxIdeas; ++i)
	{
		if (_ideas[i].empty())
		{
			_ideas[i] = idea;
			std::cout << idea << " is added" << std::endl;
			return;
		}
	}

	std::cout << "Brain ideas capacity is full" << std::endl;
};

std::string Brain::getRandomIdea() const
{
	int randomIndex = std::rand() % 99;

	return _ideas[randomIndex];
};
