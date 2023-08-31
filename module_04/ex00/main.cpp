/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:53:52 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/31 16:34:37 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) { 
	const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;

	std::cout << "Animal type: " << meta->getType() << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;
	std::cout << "WrongAnimal type: " << wrongMeta->getType() << std::endl;
	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

	std::cout << std::endl;

	std::cout << "Animal sound: ";
	meta->makeSound();
	std::cout << "Cat sound: ";
	cat->makeSound();
	std::cout << "Dog sound: ";
	dog->makeSound();
	std::cout << "WrongAnimal sound: ";
	wrongMeta->makeSound();
	std::cout << "WrongCat sound: ";
	wrongCat->makeSound();

	std::cout << std::endl;

    delete wrongCat;
	delete wrongMeta;
	delete cat;
	delete dog;
	delete meta;

    return (0);
}