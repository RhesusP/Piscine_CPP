/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:04:57 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 15:32:05 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int		main(void)
{
	ClapTrap	*clap = new ClapTrap("Clap");
	ScavTrap	*scav = new ScavTrap("Scav");

	std::cout << *clap << std::endl;
	std::cout << *scav << std::endl;
	clap->attack("target");
	scav->attack("target");
	clap->takeDamage(10);
	scav->takeDamage(10);
	clap->beRepaired(10);
	scav->beRepaired(10);
	std::cout << *clap << std::endl;
	std::cout << *scav << std::endl;
	delete clap;
	delete scav;
	return (0);
}