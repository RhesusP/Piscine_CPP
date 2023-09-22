/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:11:49 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/22 11:52:21 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp" 


/**
 * Classe abstraite : contient une methode pure
 * Defini le comportement des enfants mais ne peut pas elle-meme faire ceraines actions (methodes pures).
 * 
 */

class AMateria {
	protected:
		std::string	_type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & m);
		
		AMateria&	operator=(AMateria const & rhs);
		
		~AMateria(void);
		std::string const &	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

#endif
