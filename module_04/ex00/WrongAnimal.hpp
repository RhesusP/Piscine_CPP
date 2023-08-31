/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:29:07 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/31 21:39:30 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &a);
		~WrongAnimal(void);
		void	makeSound(void) const;
		std::string	getType(void) const;
		WrongAnimal&	operator=(WrongAnimal const & rhs);
};

#endif