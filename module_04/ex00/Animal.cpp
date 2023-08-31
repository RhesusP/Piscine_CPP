/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:01:32 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/31 15:35:08 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "An Animal has been created." << std::endl;
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
