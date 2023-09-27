/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:50:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 11:30:41 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(Animal const & a);
		virtual ~Animal(void);
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
		virtual Animal&	operator=(Animal const & rhs);
};

#endif
