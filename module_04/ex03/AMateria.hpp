/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:11:49 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 10:52:17 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp" 

class AMateria {
	protected:
		std::string	_type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & m);
		
		AMateria&	operator=(AMateria const & rhs);
		
		virtual 			~AMateria(void);
		std::string const &	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

#endif
