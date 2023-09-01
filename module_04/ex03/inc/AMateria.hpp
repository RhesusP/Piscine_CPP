/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:07:07 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 12:52:20 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(std::string const & type);
		~AMateria();
		std::string const & getType() const;	// Returns the materia type;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
