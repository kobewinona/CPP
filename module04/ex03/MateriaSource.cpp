/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:22:22 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 18:28:42 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// @defgroup constructors
MateriaSource::MateriaSource()
{
	for (int i = 0; i < _maxMateriaSources; ++i)
		_lerantMaterias[i] = NULL;
};

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < _maxMateriaSources; ++i)
		_lerantMaterias[i] = other._lerantMaterias[i];
};

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < _maxMateriaSources; ++i)
			_lerantMaterias[i] = other._lerantMaterias[i];
	}

	return (*this);
};

// @def destractor
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _maxMateriaSources; ++i)
		delete _lerantMaterias[i];
};

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	while (_lerantMaterias[i] != NULL)
		i++;

	if (i < _maxMateriaSources)
		_lerantMaterias[i] = m;
	else
		std::cout << "full source capacity reached" << std::endl;
};

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < _maxMateriaSources; ++i)
	{
		if (_lerantMaterias[i]->getType() == type)
			return _lerantMaterias[i]->clone();
	}

	return NULL;
};
