/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:55:45 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 18:03:37 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string.h>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string const &	getType();
		void	setType(std::string type);
};

#endif
