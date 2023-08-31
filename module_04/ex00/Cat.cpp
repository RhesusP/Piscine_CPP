/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:09:51 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/31 15:17:56 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	Animal::type = "Cat";
	std::cout << "A cat has been created." << std::endl;
}

Cat::~Cat(void) {
	std::cout << "A cat has been destroyed." << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "Meow Meow 🐱" << std::endl;
}
