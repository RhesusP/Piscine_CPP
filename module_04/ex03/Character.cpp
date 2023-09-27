/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:44:23 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 11:27:35 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	_name = "default character";
}

Character::Character(std::string name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	_name = name;
}

Character::Character(Character const & c) {
	*this = c;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
		}
	}
}

Character&	Character::operator=(Character const & rhs) {
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}


std::string const & Character::getName(void) const {
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	if (!m || m == NULL)
		return ;
	for (int i = 0; i < 4 ; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Character " << _name << " inventory is full" << std::endl;
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx <= 3 && this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
	}
}

AMateria*	Character::getInventoryItem(int idx) const {
	if (idx >= 0 && idx <= 3) {
		if (_inventory[idx]) {
			return (_inventory[idx]);
		}
	}
	return (NULL);
}

std::ostream&	operator<<(std::ostream& o, Character& rhs) {
	AMateria*	tmp;
	o << "name: " << rhs.getName() << std::endl;
	for (int i = 0; i < 4; i++) {
		tmp = rhs.getInventoryItem(i);
		if (tmp) {
			o << "[" << i << "]: " << tmp->getType() << std::endl;
		}
		else {
			o << "[" << i << "]: null" << std::endl;
		}
	}
	return o;
}
