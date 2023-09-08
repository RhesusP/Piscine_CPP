/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:04:57 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/08 13:39:25 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	// ClapTrap	bob("Bob");
	// ClapTrap	todd("Todd");
	// FragTrap	jean("Jean");
	// ScavTrap	jeanne("Jeanne");
	// ScavTrap	jacques("Jacques");

	// bob.attack("Todd");
	// todd.takeDamage(1);
	// std::cout << bob << std::endl << todd << std::endl;
	// jean.highFivesGuys();
	// jean.attack("Jacques");
	// jacques.takeDamage(jean.getAttack());
	// jeanne.guardGate();

	DiamondTrap	diamond("Pierre");
	std::cout << std::endl << diamond << std::endl;
	diamond.whoAmI();
	diamond.attack("toto");
	diamond.guardGate();
	std::cout << std::endl;
	return (0);
}
