/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:04:57 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 15:34:49 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// Generate main with tests for my FragTrap, ScavTrap and ClapTrap classes
int	main(void) {
	ClapTrap	bob("Bob");
	ClapTrap	todd("Todd");
	FragTrap	jean("Jean");
	ScavTrap	jeanne("Jeanne");
	ScavTrap	jacques("Jacques");

	bob.attack("Todd");
	todd.takeDamage(1);
	std::cout << bob << std::endl << todd << std::endl;
	jean.highFivesGuys();
	jean.attack("Jacques");
	jacques.takeDamage(jean.getAttack());
	jeanne.guardGate();
	return (0);
}
