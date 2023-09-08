/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:04:57 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/08 13:26:41 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int		main(void)
{
	ClapTrap	*clap = new ClapTrap("Clap");
	ScavTrap	*scav = new ScavTrap("Scav");

	std::cout << std::endl << *clap << std::endl;
	std::cout << *scav << std::endl << std::endl;
	clap->attack("target");
	scav->attack("target");
	clap->takeDamage(10);
	scav->takeDamage(10);
	clap->beRepaired(10);
	scav->beRepaired(10);
	std::cout << std::endl << *clap << std::endl;
	std::cout << *scav << std::endl << std::endl;
	delete clap;
	delete scav;
	return (0);
}