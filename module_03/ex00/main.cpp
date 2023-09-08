/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:04:57 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/08 09:05:39 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	bob("Bob");
	ClapTrap	todd("Todd");

	bob.attack("Todd");
	todd.takeDamage(0);
	std::cout << bob << std::endl << todd << std::endl;
	
	std::cout << std::endl;
	todd.takeDamage(10);
	std::cout << todd << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		bob.attack("Todd");
	}
	std::cout << bob << std::endl << std::endl;

	todd.beRepaired(10);
	std::cout << todd << std::endl;
	
	return (0);
}