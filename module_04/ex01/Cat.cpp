/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:09:51 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 10:44:31 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "A cat has been created." << std::endl;
	Animal::type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const & c) : Animal(c) {
	std::cout << "A cat has been created by copy constructor." << std::endl;
	*this = c;
}

Cat::~Cat(void) {
	std::cout << "A cat has been destroyed." << std::endl;
	delete _brain;
}

void	Cat::makeSound(void) const {
	std::cout << "Meow Meow 🐱" << std::endl;
}

Brain*	Cat::getBrain(void) const {
	return (this->_brain);
}

Cat&	Cat::operator=(Cat const & rhs) {
	Animal::operator=(rhs);
	this->_brain = rhs._brain;
	return (*this);
}
