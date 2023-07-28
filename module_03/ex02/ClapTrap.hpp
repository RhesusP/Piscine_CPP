/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:43:33 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 15:37:42 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attack;
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & c);
		ClapTrap(std::string name, int hit, int energy, int attack);
		ClapTrap& operator=(ClapTrap const &rhs);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void) const;
		int getHit(void) const;
		int getEnergy(void) const;
		int getAttack(void) const;
};

std::ostream&	operator<<(std::ostream& o, ClapTrap& rhs);

#endif
