/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:00:20 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/08 13:23:33 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap(void);
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & rhs);
		ScavTrap& operator=(ScavTrap const &rhs);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate(void);
};

#endif