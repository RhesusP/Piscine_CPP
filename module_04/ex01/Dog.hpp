/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:22:11 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 10:55:14 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog(void);
		Dog(Dog const & d);
		~Dog(void);
		void	makeSound(void) const;
		Brain	*getBrain(void) const;
		Dog&	operator=(Dog const & rhs);
};

#endif
