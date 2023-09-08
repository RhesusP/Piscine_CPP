/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:29:16 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/08 09:38:07 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragTrap", 100, 100, 30) {
	std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &rhs) {
	_name = rhs.getName();
	_hit = rhs.getHit();
	_energy = rhs.getEnergy();
	_attack = rhs.getAttack();
	return (*this);
}

FragTrap::FragTrap(FragTrap const & rhs) : ClapTrap(rhs.getName()) {
	*this = rhs;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " is asking for high fives" << std::endl;
}
