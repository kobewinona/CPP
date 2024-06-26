/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:11:03 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 13:12:04 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// @defgroup destractor
Brain::Brain() : _currentIdeaIndex(0)
{
	for (int i = 0; i < 100; ++i)
	{
		std::ostringstream oss;
		oss << "idea #" << i;
		_ideas[i] = oss.str();
	}

	std::cout << GRAY << "Brain is created" << RESET << std::endl;
};

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < _maxIdeas; ++i)
		_ideas[i] = other._ideas[i];

	_currentIdeaIndex = other._currentIdeaIndex;

	std::cout << GRAY << "Brain is copied" << RESET << std::endl;
};

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < _maxIdeas; ++i)
			_ideas[i] = other._ideas[i];
	}

	_currentIdeaIndex = other._currentIdeaIndex;

	std::cout << GRAY << "Brain is assigned" << RESET << std::endl;

	return (*this);
};

// @def destractor
Brain::~Brain()
{
	std::cout << GRAY << "Brain is destroyed" << RESET << std::endl;
};

// @defgroup memeber functions
void Brain::addIdea(std::string idea)
{
	_ideas[_currentIdeaIndex % 100] = idea;
	_currentIdeaIndex += 1;
};

std::string Brain::getIdea(const int index) const
{
	return _ideas[index];
};

std::string Brain::getRandomIdea() const
{
	int randomIndex = std::rand() % 99;

	return _ideas[randomIndex];
};
