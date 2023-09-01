/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:53:52 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 12:00:11 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void) {

	// ok
	AAnimal	*cat = new Cat();
	cat->makeSound();

	// error because abstract class
	// AAnimal *animal = new AAnimal();
	// animal->makeSound();

	// error because abstract class
	// AAnimal cat1 = Cat();
	// cat1.makeSound();

	delete cat;
    return (0);
}
