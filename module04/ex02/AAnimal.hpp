/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:16:27 by dklimkin          #+#    #+#             */
/*   Updated: 2024/06/09 14:11:58 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

#define RESET "\033[0m"
#define GRAY "\033[90m"

class AAnimal
{
private:
	static const std::string _defaultType;

protected:
	std::string _type;

public:
	AAnimal(std::string _type);
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();
	virtual AAnimal *clone() const = 0;

	std::string getType() const;
	virtual void makeSound() const = 0;
	virtual void addIdea(std::string idea) = 0;
	virtual std::string getIdea(const int index) const = 0;
	virtual std::string getRandomIdea() const = 0;
};

#endif
