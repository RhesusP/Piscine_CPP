/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:30:55 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/31 21:44:04 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "A WrongAnimal has been created." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & a) {
	std::cout << "A WrongAnimal has been created by copy constructor." << std::endl;
	*this = a;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "A WrongAnimal has been destroyed." << std::endl;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "What wrong noise should I make ?" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (this->type);
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const & rhs) {
	this->type = rhs.type;
	return (*this);
}