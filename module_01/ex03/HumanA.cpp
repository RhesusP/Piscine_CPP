/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:05:04 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 17:57:35 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {
}

HumanA::~HumanA(void) {
}

void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}