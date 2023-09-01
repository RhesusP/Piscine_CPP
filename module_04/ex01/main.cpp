/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:53:52 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 11:24:24 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void) { 
	std::cout << "======= Test deep copy =======" << std::endl;
	Brain	*gontrand = new Brain();
	Brain	*bertrand;

	gontrand->setIdea("Is it a good idea ?", 0);
	bertrand = new Brain(*gontrand);

	gontrand->setIdea("I belong (again) to Gontrand", 0);
	std::cout << "Gontrand 1st idea: " << gontrand->getIdea(0) << std::endl;
	delete gontrand;
	std::cout << "Bertrand 1st idea: " << bertrand->getIdea(0) << std::endl;
	delete bertrand;

	std::cout << std::endl << "======= Test leaks =======" << std::endl;
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	delete dog;
	delete cat;

	std::cout << std::endl;

	Animal	*tab[4];

	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			tab[i] = new Cat();
		}
		else {
			tab[i] = new Dog();
		}
	}
	for (int i = 0; i < 4; i++) {
		delete tab[i];
	}
    return (0);
}
