/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:16:22 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 08:57:14 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp" 

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & i);
		~Ice(void);

		Ice&	operator=(Ice const & rhs);
		virtual void		use(ICharacter& target);
		virtual AMateria* 	clone(void) const;
};

#endif