/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:44:23 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/22 11:39:05 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = nullptr;
	}
	_name = "default character";
}

Character::Character(std::string name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = nullptr;
	}
	_name = name;
}

Character::~Character(void) {}

std::string const & Character::getName(void) const {
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	if (!m || m == nullptr)
		return ;
	for (int i = 0; i < 4 ; i++) {
		if (this->_inventory[i] == nullptr) {
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx <= 3) {
		this->_inventory[idx]->use(target);
	}
}
