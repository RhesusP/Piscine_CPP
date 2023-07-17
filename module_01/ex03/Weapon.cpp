/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:52:29 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 17:59:30 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::~Weapon(void) {
}

std::string const &	Weapon::getType(void) {
	std::string &ref = this->_type;
	return (ref);
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}
