/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:23:53 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 10:55:46 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "A dog as been created" << std::endl;
	Animal::type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const & d) : Animal(d) {
	std::cout << "A dog as been created by copy constructor" << std::endl;
	*this = d;
}

Dog::~Dog(void) {
	std::cout << "A dog has been destroyed" << std::endl;
	delete _brain;
}

void	Dog::makeSound(void) const {
	std::cout << "Wouf wouf 🐶" << std::endl;
}

Brain*	Dog::getBrain(void) const {
	return (this->_brain);
}

Dog&	Dog::operator=(Dog const & rhs) {
	Animal::operator=(rhs);
	this->_brain = rhs._brain;
	return (*this);
}
