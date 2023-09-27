/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:36:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 11:18:56 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
	public:
		Character(void);
		Character(std::string name);
		Character(Character const & c);
		~Character();
		Character&	operator=(Character const & rhs);
		std::string	const & getName(void) const;
		AMateria*	getInventoryItem(int idx) const;
		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter& target);
};

std::ostream&	operator<<(std::ostream& o, Character& rhs);

#endif