/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:16:49 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 14:12:27 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

const std::string AAnimal::_defaultType = "unknown type";

// @defgroup constructors
AAnimal::AAnimal(std::string type) : _type(type) {
  std::cout << GRAY << "AAnimal " << type << " is created" << RESET
            << std::endl;
};

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {
  std::cout << GRAY << "AAnimal " << _type << " is copied" << RESET
            << std::endl;
};

AAnimal &AAnimal::operator=(const AAnimal &other) {
  if (this != &other)
    _type = other._type;

  std::cout << GRAY << "AAnimal " << _type << " is assigned" << RESET
            << std::endl;

  return (*this);
};

// @def destructor
AAnimal::~AAnimal() {
  std::cout << GRAY << "AAnimal " << _type << " is destroyed" << RESET
            << std::endl;
};

// @defgroup member functions
std::string AAnimal::getType() const { return _type; };
