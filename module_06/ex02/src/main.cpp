/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:25:36 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/02 17:29:24 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"


Base*	generate(void) {
	int		random;

	srand(time(0));
	random = rand() % 3;
	if (random == 0)
		return (new A);
	if (random == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "🎲 Class A is one of God's elect." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "🎲 Class B is one of God's elect." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "🎲 Class C is one of God's elect." << std::endl;
	else
		std::cout << "WhAt TypE IS iT ?!" << std::endl;
}

void	identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "🎲 Class A is one of God's elect." << std::endl;
		(void)a;
	} catch (std::exception & e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "🎲 Class B is one of God's elect." << std::endl;
		(void)b;
	} catch (std::exception & e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "🎲 Class C is one of God's elect." << std::endl;
		(void)c;
	} catch (std::exception & e) {}
}

int	main(void) {
	Base*	base1;

	base1 = generate();
	identify(base1);
	identify(*base1);
	
	delete base1;
	return (0);
}
