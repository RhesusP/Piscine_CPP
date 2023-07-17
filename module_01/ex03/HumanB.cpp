/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:48:34 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 18:03:39 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = 0;
}

HumanB::~HumanB(void) {
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack(void) {
	std::cout << this->_name << " attacks with their";
	if (!this->_weapon)
		std::cout << "... nothing :O" << std::endl;
	else
	std::cout << " " << this->_weapon->getType() << std::endl;
}
