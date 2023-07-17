/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:27:34 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 12:40:11 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie	*tab = new Zombie [N];
	for (int i=0 ; i < N ; i++) {
		tab[i].setName(name);
	}
	return (tab);
}
