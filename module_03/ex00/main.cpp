/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:04:57 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 14:27:53 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	bob("Bob");
	ClapTrap	todd("Todd");

	bob.attack("Todd");
	todd.takeDamage(1);
	std::cout << bob << std::endl << todd << std::endl;
	
}