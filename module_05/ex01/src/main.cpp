/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:07:20 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 16:43:13 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int	main(void) {

	std::cout << "--------------------------";
	std::cout << std::endl << "\e[1m✅ Test 1: normal behavior\e[0m" << std::endl;
	try {
		Bureaucrat	joe("Joe", 100);
		Form		form("Form", 100, 100);
	
		std::cout << joe << std::endl << form << std::endl;
		joe.signForm(form);
		std::cout << form << std::endl;
	
	} catch	(std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------";
	std::cout << std::endl << "\e[1m❌ Test 2: grade too low\e[0m" << std::endl;
	try {
		Bureaucrat	slave("The slave", 150);
		Form		form("Form", 100, 100);

		std::cout << slave << std::endl << form << std::endl;
		slave.signForm(form);
		std::cout << form << std::endl;
	} catch	(std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "---------------------------";
	std::cout << std::endl << "\e[1m❌ Test 3: double signature\e[0m" << std::endl;
	try {
		Bureaucrat	joe("Joe", 100);
		Form		form("Form", 100, 100);
	
		std::cout << joe << std::endl << form << std::endl;
		joe.signForm(form);
		std::cout << form << std::endl;
		joe.signForm(form);
		std::cout << form << std::endl;
	
	} catch	(std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "----------------------------------";
	std::cout << std::endl << "\e[1m❌ Test 4: Form grade out of bound\e[0m" << std::endl;
	try {
		Bureaucrat	joe("Joe", 100);
		Form		form("Form", 151, 100);
	
		std::cout << joe << std::endl << form << std::endl;
		joe.signForm(form);
		std::cout << form << std::endl;
		joe.signForm(form);
		std::cout << form << std::endl;
	
	} catch	(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
