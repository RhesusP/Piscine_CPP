/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:47:41 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/08 09:39:23 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	_name = "ClapTrap";
	_hit = 10;
	_energy = 10;
	_attack = 0;
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	_name = name;
	_hit = 10;
	_energy = 10;
	_attack = 0;
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & c) {
	*this = c;
}

ClapTrap::ClapTrap(std::string name, int hit, int energy, int attack) {
	_name = name;
	_hit = hit;
	_energy = energy;
	_attack = attack;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &rhs) {
	_name = rhs.getName();
	_hit = rhs.getHit();
	_energy = rhs.getEnergy();
	_attack = rhs.getAttack();
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (_energy - 1 >= 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
		_energy -= 1;
	}
	else {
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points to attack." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit == 0)
		std::cout << "Stop! ClapTrap " << _name << " is already dead!" << std::endl;
	else if (this->_hit - amount <= 0)
	{
		amount = _hit;
		_hit -= amount;
		std::cout << "ClapTrap " << _name << " is under attack! He loses " << amount << " hit points and died!" << std::endl;
	}
	else {
		_hit -= amount;
		std::cout << "ClapTrap " << _name << " is under attack! He loses " << amount << " hit points!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energy - 1 >= 0)
	{
		std::cout << "ClapTrap " << _name << " repairs itself and regains " << amount << " hit points." << std::endl;
		_energy -= 1;
		_hit += amount;
	}
	else {
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points to repair itself." << std::endl;
	}
}

std::string ClapTrap::getName(void) const {
	return (this->_name);
}

int ClapTrap::getHit(void) const {
	return (this->_hit);
}

int ClapTrap::getEnergy(void) const {
	return (this->_energy);
}

int ClapTrap::getAttack(void) const {
	return (this->_attack);
}

std::ostream&	operator<<(std::ostream& o, ClapTrap& rhs) {
	o << rhs.getName() << " has " << rhs.getHit() << " hit points, " << rhs.getEnergy() << " energy points and " << rhs.getAttack() << " attack points.";
	return (o);
}
