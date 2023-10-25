/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:07:20 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 16:45:25 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	bob("Bob", 1);
		Bureaucrat	jim("Jim", 150);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	jean("Jean", 151);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	jack("Jack", 0);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
