/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:50:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 11:51:51 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal(void);
		AAnimal(AAnimal const & a);
		virtual ~AAnimal(void);
		virtual void	makeSound(void) const = 0;	// pure virtual function makes the class abstract
		virtual std::string	getType(void) const;
		virtual	Brain	*getBrain(void) const;
		virtual AAnimal&	operator=(AAnimal const & rhs);
};

#endif
