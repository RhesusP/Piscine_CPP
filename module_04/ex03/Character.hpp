/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:36:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/22 11:29:01 by cbernot          ###   ########.fr       */
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
		Character(void);									// ok
		Character(std::string name);						// ok
		Character(Character const & c);
		~Character();										// ok
		Character&	operator=(Character const & rhs);
		std::string	const & getName(void) const;			// ok
		void		equip(AMateria* m);						// ok
		void		unequip(int idx);						// ok
		void		use(int idx, ICharacter& target);
};

#endif