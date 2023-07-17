/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:16:34 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 12:24:15 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int	main(void) {
	Zombie	alex("Alex");
	Zombie	*jeff;

	jeff = newZombie("Jeff");
	alex.announce();
	jeff->announce();
	delete jeff;
}
