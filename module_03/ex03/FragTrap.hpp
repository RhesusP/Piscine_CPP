/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:29:19 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/08 10:14:48 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	protected:
		FragTrap(void);
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const & rhs);
		FragTrap& operator=(FragTrap const &rhs);
		~FragTrap();
		void highFivesGuys(void);
};

#endif