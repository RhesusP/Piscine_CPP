/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:12:37 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 09:06:02 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & c);
		~Cure(void);

		Cure&			operator=(Cure const & rhs);
		virtual void		use(ICharacter& target); 
		virtual AMateria* 	clone(void) const;
};

#endif