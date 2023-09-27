/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:01:32 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 11:30:21 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "An Animal has been created." << std::endl;
}

Animal::Animal(Animal const & a) {
	std::cout << "An Animal has been created by copy constructor." << std::endl;
	*this = a;
}

Animal::~Animal(void) {
	std::cout << "An Animal has been destroyed." << std::endl;
}

void	Animal::makeSound(void) const {
	std::cout << "What noise should I make ?" << std::endl;
}

std::string	Animal::getType(void) const {
	return (this->type);
}

Brain	*Animal::getBrain(void) const {
	return (NULL);
}

Animal&	Animal::operator=(Animal const & rhs) {
	this->type = rhs.type;
	return (*this);
}
