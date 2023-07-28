/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:10:23 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 12:27:42 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void) {
	Point	a(0, 0);
	Point	b(6, 0);
	Point	c(5, 5);
	Point	p1(4, 1);	//p1 is inside ABC
	Point	p2(8, 3);	//p2 is outside ABC
	Point	p3(3, 0);	//p3 is on the AB segment
	Point	p4 = b;		//p4 is a point of the ABC triangle

	std::cout << "p1 is inside the ABC triangle." << std::endl;
	std::cout << "bsp result: " << bsp(a, b, c, p1) << std::endl << std::endl;
	
	std::cout << "p2 is outside the ABC triangle." << std::endl;
	std::cout << "bsp result: " << bsp(a, b, c, p2) << std::endl << std::endl;

	std::cout << "p3 is on the AB segment." << std::endl;
	std::cout << "bsp result: " << bsp(a, b, c, p3) << std::endl << std::endl;

	std::cout << "p4 is a point of the ABC triangle." << std::endl;
	std::cout << "bsp result: " << bsp(a, b, c, p4) << std::endl << std::endl;

	return 0;
}
