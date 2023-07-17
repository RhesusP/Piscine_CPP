/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:27:23 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 12:40:09 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string.h>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	setName(std::string name);
		void	announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
