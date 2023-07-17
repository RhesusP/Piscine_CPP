/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:27:14 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 12:40:12 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie(void) {
	this->_name = "Default";
	std::cout << "Zombie " << this->_name << " is born" << std::endl;
}

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << "Zombie " << this->_name << " is born" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie " << this->_name << " died" << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
