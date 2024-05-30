/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:07:53 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/30 20:01:20 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

#define RESET "\033[0m"
#define GRAY "\033[90m"

class Brain
{
private:
	std::string _ideas[100];
	static const int _maxIdeas = 100;

public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void addIdea(std::string idea);
	std::string getIdea(const int index) const;
	std::string
	getRandomIdea(void) const;
};

#endif
