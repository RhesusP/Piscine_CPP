/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:23:53 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/31 15:27:23 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	Animal::type = "Dog";
	std::cout << "A dog as been created" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "A dog has been destroyed" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "Wouf wouf 🐶" << std::endl;
}
