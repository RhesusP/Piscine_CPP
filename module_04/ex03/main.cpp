/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:25:49 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 11:27:06 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void) {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	std::cout << "----- src learn an Ice Materia -----" << std::endl;
	std::cout << *(dynamic_cast<MateriaSource*>(src)) << std::endl;
	src->learnMateria(new Cure());
	std::cout << "----- src learn an Cure Materia -----" << std::endl;
	std::cout << *(dynamic_cast<MateriaSource*>(src)) << std::endl;
	ICharacter* me = new Character("me");
	std::cout << *(dynamic_cast<Character*>(me)) << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	if (!tmp) {
		std::cout << "tmp is not created: unknown type" << std::endl;
		delete me;
		delete src;
		return (0);
	}
	std::cout << "tmp type is: " << tmp->getType() << std::endl;
	me->equip(tmp);
	std::cout << *(dynamic_cast<Character*>(me)) << std::endl;
	tmp = src->createMateria("cure");
	std::cout << "tmp type is: " << tmp->getType() << std::endl;
	me->equip(tmp);
	std::cout << *(dynamic_cast<Character*>(me)) << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	delete bob;
	delete me;
	delete src;
	return (0);
}