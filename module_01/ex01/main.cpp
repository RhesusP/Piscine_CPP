/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:33:26 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 12:40:15 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int	main(void) {
	Zombie *tab;

	tab = zombieHorde(5, "Jeff");
	for (int i=0 ; i < 5 ; i++) {
		tab->announce();
	}
	delete [] tab;
	return (0);
}
