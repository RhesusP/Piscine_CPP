/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:45:17 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 11:08:45 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp" 

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materias[4];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & m);
		~MateriaSource(void);
		MateriaSource&		operator=(MateriaSource const & rhs);
		
		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);

		AMateria*	getMateria(int idx) const;
};

std::ostream&	operator<<(std::ostream& o, MateriaSource& rhs);

#endif