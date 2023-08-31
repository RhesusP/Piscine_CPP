/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:23:53 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/31 21:36:02 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	Animal::type = "Dog";
	std::cout << "A dog as been created" << std::endl;
}

Dog::Dog(Dog const & d) : Animal(d) {
	std::cout << "A dog as been created by copy constructor" << std::endl;
	*this = d;
}

Dog::~Dog(void) {
	std::cout << "A dog has been destroyed" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "Wouf wouf 🐶" << std::endl;
}

Dog&	Dog::operator=(Dog const & rhs) {
	Animal::operator=(rhs);
	return (*this);
}
