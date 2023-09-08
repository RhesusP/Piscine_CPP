/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:07:20 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/08 10:58:57 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap", 100, 50, 20) {
	std::cout << "ScavTrap " << _name << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap " << _name << " created" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &rhs) {
	_name = rhs.getName();
	_hit = rhs.getHit();
	_energy = rhs.getEnergy();
	_attack = rhs.getAttack();
	return (*this);
}

ScavTrap::ScavTrap(ScavTrap const & rhs) : ClapTrap(rhs.getName()) {
	*this = rhs;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << _name << " destroyed" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " entered in gate keeper mode" << std::endl;
}
