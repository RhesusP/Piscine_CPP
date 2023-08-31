/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:30:55 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/31 16:33:07 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "A WrongAnimal has been created." << std::endl;
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
