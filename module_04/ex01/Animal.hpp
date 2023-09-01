/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:50:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 11:27:11 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(Animal const & a);
		virtual ~Animal(void);
		virtual void	makeSound(void) const;
		virtual std::string	getType(void) const;
		virtual	Brain	*getBrain(void) const;
		virtual Animal&	operator=(Animal const & rhs);
};

#endif
