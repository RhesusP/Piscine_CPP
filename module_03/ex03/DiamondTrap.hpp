/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:16:37 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/08 10:52:57 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
		DiamondTrap(void);

	public:
		DiamondTrap(std::string name);
		DiamondTrap(FragTrap const & rhs);
		DiamondTrap& operator=(DiamondTrap const &rhs);
		~DiamondTrap(void);
		void attack(const std::string& target);
		void whoAmI(void) const;
};

#endif