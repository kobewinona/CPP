/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:16:27 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 13:18:50 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

#define RESET "\033[0m"
#define GRAY "\033[90m"
#define RED "\033[31m"

class WrongAnimal
{
private:
	static const std::string _defaultType;

protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(std::string _type);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	virtual ~WrongAnimal();

	std::string getType() const;
	void makeSound() const;
};

#endif
