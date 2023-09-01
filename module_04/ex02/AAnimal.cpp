/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:01:32 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 11:54:43 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "An AAnimal has been created." << std::endl;
}

AAnimal::AAnimal(AAnimal const & a) {
	std::cout << "An AAnimal has been created by copy constructor." << std::endl;
	*this = a;
}

AAnimal::~AAnimal(void) {
	std::cout << "An AAnimal has been destroyed." << std::endl;
}

void	AAnimal::makeSound(void) const {
	std::cout << "What noise should I make ?" << std::endl;
}

std::string	AAnimal::getType(void) const {
	return (this->type);
}

Brain	*AAnimal::getBrain(void) const {
	return (NULL);
}

AAnimal&	AAnimal::operator=(AAnimal const & rhs) {
	this->type = rhs.type;
	return (*this);
}
