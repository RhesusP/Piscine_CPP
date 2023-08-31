/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:35:23 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/31 21:43:37 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	WrongAnimal::type = "WrongCat";
	std::cout << "A wrong cat has been created." << std::endl;
}

WrongCat::WrongCat(WrongCat const & c) : WrongAnimal(c) {
	std::cout << "A cat has been created by copy constructor." << std::endl;
	*this = c;
}

WrongCat::~WrongCat(void) {
	std::cout << "A wrong cat has been destroyed." << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Meow Meow 🐱" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const & rhs) {
	WrongAnimal::operator=(rhs);
	return (*this);
}