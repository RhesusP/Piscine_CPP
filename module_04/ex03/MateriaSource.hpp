/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:45:17 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/22 11:49:33 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & m);
		~MateriaSource(void);
		MateriaSource&	operator=(MateriaSource const & rhs);
		
		void			learnMateria(AMateria*);
		AMateria		*createMateria(std::string const & type);
};

#endif