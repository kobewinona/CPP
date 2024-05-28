/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:24:14 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/28 13:31:17 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

#define FT_MAX_HP 100
#define FT_MAX_EP 100
#define FT_DMG 30

class FlagTrap : public ClapTrap
{
public:
	FlagTrap(void);
	FlagTrap(std::string name);
	FlagTrap(const FlagTrap &other);
	FlagTrap &operator=(const FlagTrap &other);
	~FlagTrap(void);

	void highFivesGuys(void);
};

#endif
