/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:43:33 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/08 10:56:09 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attack;
		ClapTrap(void);
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & c);
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