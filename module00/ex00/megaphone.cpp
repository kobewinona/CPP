/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:06:01 by dklimkin          #+#    #+#             */
/*   Updated: 2024/04/04 19:36:15 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}

	for (int i = 1; i < argc; ++i) {
        std::string str = argv[i];

		for (unsigned long j = 0; j < str.length(); ++j) {
			str[j] = std::toupper(str[j]);
		}

		std::cout << str << (i + 1 != argc ? " " : "");
    }
	
	return (std::cout << std::endl, EXIT_SUCCESS);
}
